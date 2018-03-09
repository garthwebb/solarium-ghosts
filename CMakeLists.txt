cmake_minimum_required(VERSION 3.9)
project(Solarium_Ghosts)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

SET(MCU "atmega168")  # atmega168pb
SET(F_CPU "8000000")
SET(CMAKE_SYSTEM_NAME Generic)

# For some reason, these paths have to be absolute, otherwise
# CLion won't be able to find headers etc.
SET(CMAKE_C_COMPILER /opt/local/bin/avr-gcc)
SET(CMAKE_CXX_COMPILER /opt/local/bin/avr-g++)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_C_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -Os")
SET(CMAKE_C_LINK_FLAGS "-mmcu=${MCU}")

SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

add_executable(Solarium_Ghosts src-cpp/i2c/i2c_master.c src-cpp/PCA9635.cpp src-cpp/PCA9635.h src-cpp/ray.cpp src-cpp/ray.h src-cpp/beam.cpp src-cpp/beam.h src-cpp/main.cpp src-cpp/main.h)