//
// Created by Garth Webb on 3/8/18.
//

#include "main.h"
#include "i2c/i2c_master.h"
#include "ray.h"
#include "serial.h"

void init() {
    init_serial();
    i2c_init();
}

int main() {
    init();

    send("Init complete\n");

    device_list_t *devices = probe_devices();
    if (devices != NULL) {
        send_int("Found %d devices\n", devices->length);
    } else {
        send("== NO DEVICES FOUND ON BUS ==\n\n");
        return 1;
    }

    ray_list_t *ray_list = build_rays_from_devices(devices);
    if (ray_list != NULL) {
        send_int("Created %d ray(s)\n", ray_list->length);
    } else {
        send("== FAILED TO CREATE RAYS ==\n\n");
        return 1;
    }

    ray_t *ray;
    for (int ray_idx = 0; ray_idx < ray_list->length; ray_idx++) {
        ray = ray_list->rays[ray_idx];

        for (uint8_t beam_idx = 0; beam_idx < NUM_BEAMS; beam_idx++) {
            set_beam_rgb(ray, beam_idx, 128, 255, 0);
        }
        update_ray(ray);
    }

    send("Rays updated\n\n");

    int count = 0;
    uint8_t red = 127;
    uint8_t green = 0;
    uint8_t blue = 255;
    while (1) {
        /*
        for (uint8_t i = 0; i < NUM_BEAMS; i++) {
            set_beam_rgb(ray, i, red, green, blue);
        }
        update_ray(ray);

        count++;
        red = (red+count)%256;
        green = (green+count)%256;
        blue = (blue+count)%256;
         */
    }
}
