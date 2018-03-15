//
// Created by Garth Webb on 3/8/18.
//

#include <stdlib.h>
#include "PCA9635.h"
#include "i2c_master.h"
#include "serial.h"

#define TO_WRITE_ADDR(addr) ((addr) << 1)
#define TO_READ_ADDR(addr) (((addr) << 1) + 1)

device_list_t* create_device_list() {
    device_address_list_t *addresses = probe_devices();
    if (!addresses) {
        return NULL;
    }

    device_list_t *devices = (device_list_t *) malloc(sizeof(device_list_t));
    if (!devices) {
        DEBUG("E: malloc failed for device_list_t\n");
        return NULL;
    }

    devices->length = addresses->length;
    devices->list = (device_t **) malloc(sizeof(device_t*) * devices->length);
    if (!devices->list) {
        DEBUG("E: malloc failed for device_t*\n");
        return NULL;
    }

    for (uint8_t i = 0; i < addresses->length; i++) {
        devices->list[i] = create_device(addresses->list[i]);
        if (!devices->list[i]) {
            break;
        }
    }

    free(addresses);

    return devices;
}

device_address_list_t* probe_devices() {
    send("Probing for devices ...\n");
    device_address_list_t *list = (device_address_list_t *) malloc(sizeof(device_address_list_t));
    if (!list) {
        DEBUG("E: malloc failed for device_address_list_t\n");
        return NULL;
    }

    list->length = 0;

    for (uint8_t addr = 0; addr < 128; addr++) {
        if (addr == ADR_ALLCALL) {
            continue;
        }
        if (addr == ADR_SWRESET) {
            continue;
        }

        // Non-zero return means no ACK
        if (i2c_start(TO_WRITE_ADDR(addr))) {
            continue;
        }

        // Finish this do-nothing command
        i2c_stop();

        send_int("-- %d found\n", addr);
        list->list[list->length] = addr;
        list->length++;
    }

    return list;
}

device_t* create_device(uint8_t addr) {
    device_t *device = (device_t *) malloc(sizeof(device_t));
    if (!device) {
        DEBUG("E: malloc failed for device_t\n");
        return NULL;
    }

    device->addr = addr;

    // The LSB of the address determines whether the PCA9635 is being written to (0)
    // or read from (1)
    device->write_addr = TO_WRITE_ADDR(addr);
    device->read_addr = TO_READ_ADDR(addr);

    clear_values(device);

    init_device(device);

    return device;
}

void clear_values(device_t *device) {
    for (int i = 0; i < NUM_LED_VALUES; i++) {
        device->value[i] = 0;
    }
}

void init_device(device_t *device) {
    // Disabled MODE1_SLEEP which is set by default, retains ALLCALL so devices
    // continue to respond to this address
    write_register(device, REG_MODE1, MODE1_ALLCALL);

    // Disables MODE2_OUTDRV which is set by default, making the LED outputs
    // open-drain rather than totem-pole.  Retains LEDN1.
    write_register(device, REG_MODE2, MODE2_LEDN1);

    // Make sure all LED outs are set for PWM (not full on, not full off, etc)
    uint8_t all_pwm = ledout_val(LEDOUT_PWM, LEDOUT_PWM, LEDOUT_PWM, LEDOUT_PWM);

    write_register(device, REG_LEDOUT0, all_pwm);
    write_register(device, REG_LEDOUT1, all_pwm);
    write_register(device, REG_LEDOUT2, all_pwm);
    write_register(device, REG_LEDOUT3, all_pwm);
}

uint8_t write_register(device_t *device, uint8_t reg, uint8_t val) {
    if (i2c_start(device->write_addr)) {
        send_int("Send to addr %d did not go well\n\n", device->write_addr);
        return 0;
    }
    if (i2c_write(reg)) {
        return 0;
    }
    if (i2c_write(val)) {
        return 0;
    }
    return 1;
}

void update_devices(device_list_t *devices) {
    for (uint8_t i = 0; i < devices->length; i++) {
        update_device(devices->list[i]);
    }
}

void update_device(device_t *device) {
    // Update the device by writing all values to it in one message
    if (i2c_writeReg(device->write_addr, AUTO_INCREMENT_BRIGHTNESS_REGISTER, device->value, NUM_LED_VALUES)) {
        DEBUG("E: i2c_writeReg failed\n");
    }
}
