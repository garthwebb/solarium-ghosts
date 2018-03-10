//
// Created by Garth Webb on 3/8/18.
//

#include <stdlib.h>
#include "PCA9635.h"
#include "i2c/i2c_master.h"

device_t* create_device(uint8_t addr) {
    device_t *device = (device_t *) malloc(sizeof(device_t));

    device->addr = addr;
    clear_values(device);

    init_device(device);

    return device;
}

void clear_values(device_t *device) {
    for (int i = 0; i < NUM_VALUES; i++) {
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
    if (i2c_start(device->addr)) {
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

void update_device(device_t *device) {
    // Update the device by writing all values to it in one message
    i2c_writeReg(device->addr, AUTO_INCREMENT_BRIGHTNESS_REGISTER, device->value, NUM_VALUES);
}
