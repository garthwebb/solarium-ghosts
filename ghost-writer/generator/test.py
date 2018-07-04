from base import Base


class Test(Base):

    def __init__(self):
        super(Test, self).__init__()
        self.led_values = [[[0, 0, 0] for _ in range(16)] for _ in range(8)]

    def get_next_frame(self, addresses):
        for ray in range(8):
            for n in range(16):
                self.led_values[ray][n][0] += 1
                self.led_values[ray][n][1] += 2
                self.led_values[ray][n][2] += 3

                self.led_values[ray][n][0] = self.led_values[ray][n][0] & 0xFF
                self.led_values[ray][n][1] = self.led_values[ray][n][1] & 0xFF
                self.led_values[ray][n][2] = self.led_values[ray][n][2] & 0xFF

        return self.led_values
