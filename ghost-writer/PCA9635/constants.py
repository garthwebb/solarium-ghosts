
# Registers

REG_MODE1 = 0x00  # Mode registers: Set behavior of PCA9635
REG_MODE2 = 0x01
REG_PWM0 = 0x02  # PWM registers: Set PWM for each LED
REG_PWM1 = 0x03
REG_PWM2 = 0x04
REG_PWM3 = 0x05
REG_PWM4 = 0x06
REG_PWM5 = 0x07
REG_PWM6 = 0x08
REG_PWM7 = 0x09
REG_PWM8 = 0x0A
REG_PWM9 = 0x0B
REG_PWM10 = 0x0C
REG_PWM11 = 0x0D
REG_PWM12 = 0x0E
REG_PWM13 = 0x0F
REG_PWM14 = 0x10
REG_PWM15 = 0x11
REG_GRPPWM = 0x12  # Group duty cycle control
REG_GRPFREQ = 0x13  # Group frequency

# Controls behavior of PWM of LEDs in 4 groups of 4 LEDs. E.g. REG_LEDOUT0 controls leds 0..3
# and REG_LEDOUT1 controls leds 4..7 etc
REG_LEDOUT0 = 0x14
REG_LEDOUT1 = 0x15
REG_LEDOUT2 = 0x16
REG_LEDOUT3 = 0x17

REG_SUBADR1 = 0x18  # User programmable I2C subaddress 1-3
REG_SUBADR2 = 0x19
REG_SUBADR3 = 0x1A
REG_ALLCALLADR = 0x1B  # All call I2C address


# Register MODE1 bits.  OR these together

# Auto increment flags
MODE1_AI2 = 0x80  # 0b10000000
MODE1_AI1 = 0x40  # 0b01000000
MODE1_AI0 = 0x20  # 0b00100000

MODE1_SLEEP = 0x10  # 0b00010000
MODE1_SUB1 = 0x08  # 0b00001000
MODE1_SUB2 = 0x04  # 0b00000100
MODE1_SUB3 = 0x02  # 0b00000010
MODE1_ALLCALL = 0x01  # 0b00000001

# Register MODE2 bits.  OR these together
MODE2_DMBLNK = 0x20  # 0b00100000
MODE2_INVRT = 0x10  # 0b00010000
MODE2_OCH = 0x08  # 0b00001000
MODE2_OUTDRV = 0x04  # 0b00000100

# These define how LED outputs respond to the MODE2_OUTDRV setting.  For PWM use this isn't important
MODE2_LEDNZ = 0x02  # 0b00000010
MODE2_LEDN1 = 0x01  # 0b00000001
MODE2_LEDN0 = 0x00  # 0b00000000

# Possible values for each of the four LEDs in each REG_LEDOUTX register
LEDOUT_DIMPWM = 0x03
LEDOUT_PWM = 0x02
LEDOUT_ON = 0x01
LEDOUT_OFF = 0x00

# Addresses all devices on the I2C bus
ADR_ALLCALL = 0x70

# Software reset
ADR_SWRESET = 0x03

# Special addresses that will not belong to any individual device
RESERVED_ADDRESSES = [ADR_ALLCALL, ADR_SWRESET]
