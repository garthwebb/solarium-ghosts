//
// Created by Garth Webb on 3/8/18.
//

#ifndef SOLARIUM_GHOSTS_BEAM_H
#define SOLARIUM_GHOSTS_BEAM_H

#include <stdint.h>

class Beam {
    // Color components of the beam.  Pointers to values in a device
    uint8_t *_red;
    uint8_t *_green;
    uint8_t *_blue;

public:

    void map_red(uint8_t *device_value);
    void map_green(uint8_t *device_value);
    void map_blue(uint8_t *device_value);

    void set_rgb(uint8_t red, uint8_t green, uint8_t blue);
};

#endif //SOLARIUM_GHOSTS_BEAM_H
