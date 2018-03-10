//
// Created by Garth Webb on 3/8/18.
//

#include <stdlib.h>
#include "ray.h"

ray_list_t* build_rays_from_devices(device_list_t *devices) {
    // There are three devices per ray (R, G, B)
    uint8_t num_rays = devices->length/3;
    ray_list_t *ray_list = (ray_list_t *) malloc(sizeof(ray_list_t));

    ray_list->rays = (ray_t **) malloc(sizeof(ray_t *) * num_rays);
    ray_list->length = num_rays;

    for (uint8_t i = 0; i < num_rays; i++) {
        ray_list->rays[i] = create_ray(devices->addresses[i],
                                       devices->addresses[i+1],
                                       devices->addresses[i+2]);
    }

    return ray_list;
}

ray_t* create_ray(uint8_t red_addr, uint8_t green_addr, uint8_t blue_addr) {
    ray_t *ray = (ray_t *) malloc(sizeof(ray_t));
    ray->size = NUM_BEAMS;

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
