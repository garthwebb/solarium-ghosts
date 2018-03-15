//
// Created by Garth Webb on 3/13/18.
//

#ifndef SOLARIUM_GHOSTS_LED_H
#define SOLARIUM_GHOSTS_LED_H

#include <stdint.h>
#include "../lib/PCA9635.h"

typedef struct led {
    uint8_t *red;
    uint8_t *green;
    uint8_t *blue;

    uint8_t hue;
    float saturation;
    float value;
} led_t;

typedef struct led_collection {
    led_t **list;
    uint8_t length;
} led_collection_t;

led_collection_t* create_led_collection(device_list_t *devices);

#endif //SOLARIUM_GHOSTS_LED_H
