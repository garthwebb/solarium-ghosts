//
// Created by Garth Webb on 3/8/18.
//

#ifndef SOLARIUM_GHOSTS_RAY_H
#define SOLARIUM_GHOSTS_RAY_H

#include <stdint.h>

#include "PCA9635.h"
#include "beam.h"

#define NUM_DEVICES 3
#define NUM_BEAMS 16

#define DEVICE_RED 0
#define DEVICE_GREEN 1
#define DEVICE_BLUE 2

class Ray {
    // Pointers to the three devices for this beam
    Device *_devices[NUM_DEVICES];

    // The number of beams in the ray
    uint8_t _size;

public:
    // Array of beam pointers this ray controls
    Beam *beams[NUM_BEAMS];

    Ray(uint8_t red_addr, uint8_t green_addr, uint8_t blue_addr);

    void update();
};

#endif //SOLARIUM_GHOSTS_RAY_H
