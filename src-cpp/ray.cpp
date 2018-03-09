//
// Created by Garth Webb on 3/8/18.
//

#include "ray.h"

Ray::Ray(uint8_t red_addr, uint8_t green_addr, uint8_t blue_addr) {
    _devices[DEVICE_RED] = new Device(red_addr);
    _devices[DEVICE_GREEN] = new Device(green_addr);
    _devices[DEVICE_BLUE] = new Device(blue_addr);

    for (int i = 0; i < NUM_BEAMS; i++) {
        beams[i] = new Beam();
        beams[i]->map_red(&_devices[DEVICE_RED]->value[i]);
        beams[i]->map_green(&_devices[DEVICE_GREEN]->value[i]);
        beams[i]->map_blue(&_devices[DEVICE_BLUE]->value[i]);
    }
}

void Ray::update() {
    for (auto &device : _devices) {
        device->update();
    }
}
