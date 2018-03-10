//
// Created by Garth Webb on 3/8/18.
//

#include <stdlib.h>
#include "beam.h"

beam_t* create_beam(uint8_t *red, uint8_t *green, uint8_t *blue) {
    beam_t *beam = (beam_t *) malloc(sizeof(beam_t));

    beam->red = red;
    beam->green = green;
    beam->blue = blue;

    return beam;
}