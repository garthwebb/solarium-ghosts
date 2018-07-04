from base import Base


class Test(Base):
    def get_next_frame(self, addresses):
        led_values = []

        for ray in range(8):
            led_values[ray] = led_values[ray] or []
            for n in range(16):
                led_values[ray][n] = led_values[ray][n] or [0, 0, 0]
                led_values[ray][n][0] += 1
                led_values[ray][n][1] += 2
                led_values[ray][n][2] += 3

                led_values[ray][n][0] = led_values[ray][n][0] & 0xFF
                led_values[ray][n][1] = led_values[ray][n][1] & 0xFF
                led_values[ray][n][2] = led_values[ray][n][2] & 0xFF
