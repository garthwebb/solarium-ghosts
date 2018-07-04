import logging

from driver import LightBase
from ray import Ray
from i2c import I2C

logger = logging.getLogger('solarium')


class Solarium(LightBase):

    def __init__(self, args):
        super(Solarium, self).__init__(args)

        i2c = I2C()
        addresses = i2c.scan_bus()
        logger.debug("Found device addresses: {}".format(addresses))

        self.rays = []
        self.led_values = None

        for idx in range(0, len(addresses)/3, 3):
            ray = Ray(i2c, addresses[idx], addresses[idx+1], addresses[idx+2])
            self.rays.append(ray)

    def set_leds(self, led_values):
        if not led_values:
            return

        self.led_values = led_values

    def send_data(self):
        for idx, ray_leds in enumerate(self.led_values):
            ray = self.rays[idx]
            ray.write_leds(ray_leds)
