cmake_minimum_required(VERSION 3.9)
project(Solarium_Ghosts C)

set(CMAKE_C_STANDARD 99)

SET(MCU "atmega168")  # atmega168pb
SET(F_CPU "8000000")
SET(CMAKE_SYSTEM_NAME Generic)

# For some reason, these paths have to be absolute, otherwise
# CLion won't be able to find headers etc.
SET(CMAKE_C_COMPILER /opt/local/bin/avr-gcc)
SET(CMAKE_CXX_COMPILER /opt/local/bin/avr-g++)

SET(CMAKE_C_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -Os")
SET(CMAKE_C_LINK_FLAGS "-mmcu=${MCU}")

SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

add_executable(Solarium_Ghosts
        src/full-ray-beam/main.c
        src/full-ray-beam/main.h
        src/full-ray-beam/beam.c
        src/full-ray-beam/beam.h
        src/lib/PCA9635.c
        src/lib/PCA9635.h
        src/lib/serial.c
        src/lib/serial.h
        src/full-ray-beam/ray.c
        src/full-ray-beam/ray.h
        src/lib/i2c_master.c
        src/lib/i2c_master.h
        src/basic-device/main.c
        src/basic-device/main.h
        src/basic-device/led.c src/basic-device/led.h)