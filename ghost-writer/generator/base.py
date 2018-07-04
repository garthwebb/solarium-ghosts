

class Base(object):

    DEFAULT_MAX_VALUE = 255

    def __init__(self, **kwargs):
        self.addresses = []
        self.max_value = self.DEFAULT_MAX_VALUE

    def set_max_value(self, max_value):
        self.max_value = max_value

    def get_next_frame(self, addresses):
        """
        Generate the LED values needed for the next frame
        :return:
        """
        pass
