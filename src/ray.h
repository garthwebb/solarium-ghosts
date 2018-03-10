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

typedef struct ray {
    // Pointers to the three devices for this beam
    device_t *devices[NUM_DEVICES];

    // The number of beams in the ray
    uint8_t size;

    // Array of beam pointers this ray controls
    beam_t *beams[NUM_BEAMS];
} ray_t;

ray_t* create_ray(uint8_t red_addr, uint8_t green_addr, uint8_t blue_addr);
void set_beam_rgb(ray_t *ray, uint8_t num, uint8_t red, uint8_t green, uint8_t blue);
void update_ray(ray_t *ray);

#endif //SOLARIUM_GHOSTS_RAY_H
