//
// Created by Garth Webb on 3/8/18.
//

#include "beam.h"

void Beam::map_red(uint8_t *device_value) {
    _red = device_value;
}

void Beam::map_green(uint8_t *device_value) {
    _green = device_value;
}
void Beam::map_blue(uint8_t *device_value) {
    _blue = device_value;
}

void Beam::set_rgb(uint8_t red, uint8_t green, uint8_t blue) {
    *_red = red;
    *_green = green;
    *_blue = blue;
}