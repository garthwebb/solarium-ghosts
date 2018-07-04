import time
import logging
import pkgutil
import importlib
import sys

import generator
import driver

logger = logging.getLogger('controller')


class Controller(object):
    DEFAULT_FPS = 24

    def __init__(self):
        self.frame_start = None

        self.blue_driver = None   # type: driver.BlueBase
        self.light_driver = None  # type: driver.LightBase

        self.fps = None
        self.frame_seconds = None
        self.init_frame_rate(self.DEFAULT_FPS)

        self.generator = None
        self.current_generator = None
        self.current_args = None
        self.generators = []
        self.load_generators()

    def init_frame_rate(self, fps):
        self.fps = fps
        self.frame_seconds = 1.0/fps

    def load_generators(self):
        """Loads (or reloads) all pattern generators."""
        package = generator
        prefix = package.__name__ + "."

        # Load or reload all generator modules.
        for importer, modname, ispkg in pkgutil.iter_modules(package.__path__, prefix):
            if ispkg:
                continue
            basename = modname[len(prefix):]
            try:
                module = self.load_single_generator(basename, modname)
            except Exception as e:
                logger.exception('Could not load processor "{}": {}'.format(basename, e.message))

        # Regenerate generator map
        new_generators = {}
        for g in generator.Base.__subclasses__():
            new_generators[g.__name__.lower()] = g
        self.generators = new_generators

    def load_single_generator(self, base_name, module_name):
        if base_name in self.generators:
            module = reload(module_name)
            logger.info('Reloaded processor "{}"'.format(base_name))
        else:
            module = importlib.import_module(module_name)
            logger.info('Loaded processor "{}"'.format(base_name))
        return module

    def set_generator(self, generator_name, generator_args=None):
        """Sets the active processor, which must already be loaded into
        `self.processors`.

        Raises `ValueError` if processor is unknown.
        """
        self.generator = self.build_generator(generator_name, generator_args)
        self.current_generator = generator_name
        self.current_args = generator_args

    def build_generator(self, name, args=None):
        """Builds a processor instance."""
        args = args or {}
        generator = self.generators.get(name)
        if not generator:
            raise ValueError('Generator "{}" does not exist'.format(name))
        try:
            return generator(**args)
        except Exception as e:
            raise ValueError('Generator "{}" could not be created: {}'.format(name, str(e)))

    def set_light_driver(self, driver_name, driver_args):
        try:
            module = importlib.import_module("driver.{}".format(driver_name))
        except ImportError as e:
            print "Error: Light driver '{}' does not exist or could not be loaded: {}".format(driver_name, e)
            sys.exit(0)

        self.light_driver = getattr(module, driver_name.title())(driver_args)
        logger.info("Loaded light driver '{}' with max LED value {}"
                    .format(driver_name, self.light_driver.MAX_LED_VALUE))

    def set_blue_driver(self, driver_name, driver_args):
        try:
            module = importlib.import_module("driver.{}".format(driver_name))
        except ImportError as e:
            print "Error: Blue driver '{}' does not exist or could not be loaded: {}".format(driver_name, e)
            sys.exit(0)

        self.blue_driver = getattr(module, driver_name.title())(driver_args)
        logger.info("Loaded blue driver '{}'".format(driver_name))

    def run(self):
        while True:
            self.init_loop()
            self.generate_frame()
            self.transfer_data()
            self.delay()

    def init_loop(self):
        self.frame_start = time.time()

    def generate_frame(self):
        if not self.generator:
            return
        try:
            leds = self.generator.get_next_frame(self.bt.get_addresses())
        except KeyboardInterrupt:
            raise
        except Exception as err:
            logger.exception('Error generating frame for generator {}: {}'.format(self.generator, err.message))
            logger.warning('Removing generator due to error.')
        else:
            self.light_driver.set_leds(leds)

    def transfer_data(self):
        self.light_driver.send_data()

    def delay(self):
        elapsed = time.time() - self.frame_start
        if elapsed < self.frame_seconds:
            # print "Remain: {}".format(self.frame_seconds - elapsed)
            time.sleep(self.frame_seconds - elapsed)
