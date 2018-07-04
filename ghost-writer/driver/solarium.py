from driver import LightBase

from ray import Ray
from i2c import I2C


class Solarium(LightBase):

    def __init__(self, **kwargs):
        super(Solarium, self).__init__(**kwargs)

        i2c = I2C()
        addresses = i2c.scan_bus()
        self.rays = []
        self.led_values = None

        for base_addr in addresses.count()/3:
            ray = Ray(i2c, base_addr, base_addr + 1, base_addr + 2)
            self.rays.append(ray)

    def set_leds(self, led_values):
        if not led_values:
            return

        self.led_values = led_values

    def send_data(self):
        for idx, ray_leds in enumerate(self.led_values):
            ray = self.rays[idx]
            ray.write_leds(ray_leds)
