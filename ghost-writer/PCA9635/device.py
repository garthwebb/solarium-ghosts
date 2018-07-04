import constants


class Device(object):
    i2c = None
    addr = None

    # The top 3 bits are for auto increment flags, the lower 5 are for the PWM register address.
    # This sets up an auto increment of the brightness register only, starting at the first register, PWM0
    VALUE_REGISTER = constants.MODE1_AI2 | constants.MODE1_AI0 | constants.REG_PWM0

    def __init__(self, i2c, addr):
        self.i2c = i2c
        self.addr = addr

        # Disabled MODE1_SLEEP which is set by default, retains ALLCALL so devices continue to respond to this address
        self.write_register(constants.REG_MODE1, constants.MODE1_ALLCALL)

        # Disables MODE2_OUTDRV which is set by default, making the LED outputs open-drain rather than totem-pole.
        # Retains LEDN1.
        self.write_register(constants.REG_MODE2, constants.MODE2_LEDN1)

        # Make sure all LED outs are set for PWM (not full on, not full off, etc)
        all_pwm = constants.LEDOUT_PWM << 6 | constants.LEDOUT_PWM << 4 | \
            constants.LEDOUT_PWM << 2 | constants.LEDOUT_PWM

        self.write_register(constants.REG_LEDOUT0, all_pwm)
        self.write_register(constants.REG_LEDOUT1, all_pwm)
        self.write_register(constants.REG_LEDOUT2, all_pwm)
        self.write_register(constants.REG_LEDOUT3, all_pwm)

    def write_register(self, register, value):
        self.i2c.bus.write_byte_data(self.addr, register, value)

    def write_values(self, values):
        self.i2c.bus.write_i2c_block_data(self.addr, self.VALUE_REGISTER, values)
