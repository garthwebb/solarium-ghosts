from PCA9635.device import Device


class Ray(object):
    device_red = None
    device_green = None
    device_blue = None

    def __init__(self, i2c, red_addr, green_addr, blue_addr):
        self.device_red = Device(i2c, red_addr)
        self.device_green = Device(i2c, green_addr)
        self.device_blue = Device(i2c, blue_addr)

    def write_leds(self, values):
        red_values = []
        green_values = []
        blue_values = []

        for rgb in values:
            red_values.append(rgb[0])
            green_values.append(rgb[1])
            blue_values.append(rgb[2])

        self.device_red.write_values(red_values)
        self.device_green.write_values(green_values)
        self.device_blue.write_values(blue_values)
