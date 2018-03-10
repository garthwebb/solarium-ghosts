//
// Created by Garth Webb on 3/8/18.
//

#ifndef SOLARIUM_GHOSTS_BEAM_H
#define SOLARIUM_GHOSTS_BEAM_H

#include <stdint.h>

typedef struct beam {
    // Color components of the beam.  Pointers to values in a device
    uint8_t *red;
    uint8_t *green;
    uint8_t *blue;
} beam_t;

beam_t* create_beam(uint8_t *red, uint8_t *green, uint8_t *blue);

#endif //SOLARIUM_GHOSTS_BEAM_H
