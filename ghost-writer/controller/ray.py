from PCA9635.device import Device


class Ray:
    device_red = None
    device_green = None
    device_blue = None

    def __init__(self, bus, red_addr, green_addr, blue_addr):
        self.device_red = Device(bus, red_addr)
        self.device_green = Device(bus, green_addr)
        self.device_blue = Device(bus, blue_addr)
