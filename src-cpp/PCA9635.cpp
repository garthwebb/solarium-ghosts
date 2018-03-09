//
// Created by Garth Webb on 3/7/18.
//

#include "PCA9635.h"
#include "i2c/i2c_master.h"


Device::Device(uint8_t addr) {
    _addr = addr;

    clear_values();

    init_device();
}

void Device::clear_values() {
    for (uint8_t &i : value) {
        i = 0;
    }
}

void Device::init_device() {
    // Disabled MODE1_SLEEP which is set by default, retains ALLCALL so devices
    // continue to respond to this address
    write_register(REG_MODE1, MODE1_ALLCALL);

    // Disables MODE2_OUTDRV which is set by default, making the LED outputs
    // open-drain rather than totem-pole.  Retains LEDN1.
    write_register(REG_MODE2, MODE2_LEDN1);

    // Make sure all LED outs are set for PWM (not full on, not full off, etc)
    uint8_t all_pwm = ledout_val(LEDOUT_PWM, LEDOUT_PWM, LEDOUT_PWM, LEDOUT_PWM);

    write_register(REG_LEDOUT0, all_pwm);
    write_register(REG_LEDOUT1, all_pwm);
    write_register(REG_LEDOUT2, all_pwm);
    write_register(REG_LEDOUT3, all_pwm);
}

void Device::write_register(uint8_t reg, uint8_t val) {
    i2c_start(_addr);
    i2c_write(reg);
    i2c_write(val);
}

void Device::update() {
    // Update the device by writing all values to it in one message
    i2c_writeReg(_addr, AUTO_INCREMENT_BRIGHTNESS_REGISTER, _value, NUM_VALUES);
}
