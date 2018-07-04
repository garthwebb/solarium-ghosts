import smbus
from PCA9635 import constants


class I2C(object):
    # 0 = /dev/i2c-0 (port I2C0), 1 = /dev/i2c-1 (port I2C1)
    PORT = 1
    ADR_FIRST = 0x03
    ADR_LAST = 0x77

    # Reference to the bus object
    bus = None

    def __init__(self):
        self.bus = smbus.SMBus(self.PORT)

    def scan_bus(self):
        addresses = []

        for addr in range(I2C.ADR_FIRST, I2C.ADR_LAST+1):
            # Don't probe non-device addresses
            if addr in constants.RESERVED_ADDRESSES:
                continue

            # Unpopulated addresses will throw an IOError
            try:
                self.bus.write_quick(addr)
            except IOError:
                continue

            addresses.append(addr)

        return addresses
