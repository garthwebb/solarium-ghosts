//
// Created by Garth Webb on 3/8/18.
//

#include <stdlib.h>
#include "ray.h"

ray_t* create_ray(uint8_t red_addr, uint8_t green_addr, uint8_t blue_addr) {
    ray_t *ray = (ray_t *) malloc(sizeof(ray_t));

    ray->devices[DEVICE_RED] = create_device(red_addr);
    ray->devices[DEVICE_GREEN] = create_device(green_addr);
    ray->devices[DEVICE_BLUE] = create_device(blue_addr);

    for (int i = 0; i < NUM_BEAMS; i++) {
        ray->beams[i] = create_beam(
                &(ray->devices[DEVICE_RED]->value[i]),
                &(ray->devices[DEVICE_GREEN]->value[i]),
                &(ray->devices[DEVICE_BLUE]->value[i])
        );
    }

    return ray;
}

void set_beam_rgb(ray_t *ray, uint8_t num, uint8_t red, uint8_t green, uint8_t blue) {
    *(ray->beams[num]->red) = red;
    *(ray->beams[num]->green) = green;
    *(ray->beams[num]->blue) = blue;
}

void update_ray(ray_t *ray) {
    for (int i = 0; i < NUM_DEVICES; i++) {
        update_device(ray->devices[i]);
    }
}
