//
// Created by Garth Webb on 3/8/18.
//

#ifndef SOLARIUM_GHOSTS_BEAM_H
#define SOLARIUM_GHOSTS_BEAM_H

#include <stdint.h>

#define MAX_LED_VALUE 255

typedef struct beam {
    // Color components of the beam.  Pointers to values in a device
    uint8_t *red;
    uint8_t *green;
    uint8_t *blue;

    float hue;
    float saturation;
    double value;
} beam_t;

beam_t* create_beam(uint8_t *red, uint8_t *green, uint8_t *blue);
uint8_t incr_beam_red(beam_t *beam);
uint8_t incr_beam_green(beam_t *beam);
uint8_t incr_beam_blue(beam_t *beam);
void incr_beam_hue(beam_t *beam, float amount);
void copyHSVToRGB(beam_t *beam);

#endif //SOLARIUM_GHOSTS_BEAM_H
