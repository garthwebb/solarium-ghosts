//
// Created by Garth Webb on 3/8/18.
//

#include <stdlib.h>
#include "main.h"
#include "../lib/i2c_master.h"
#include "ray.h"
#include "../lib/serial.h"

void init() {
    init_serial();
    i2c_init();
}

int main() {
    init();

    send("Init complete\n");

    device_address_list_t *devices = probe_devices();
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
    free(devices);

    ray_t *ray;
    for (int ray_idx = 0; ray_idx < ray_list->length; ray_idx++) {
        ray = ray_list->rays[ray_idx];

        for (uint8_t beam_idx = 0; beam_idx < NUM_BEAMS; beam_idx++) {
            //set_beam_rgb(ray, beam_idx, (beam_idx*MAX_LED_VALUE)/NUM_BEAMS, 0, 0);
            set_beam_hsv(ray, beam_idx, (beam_idx*360)/NUM_BEAMS, 1.0, 0);
        }
        update_ray(ray);
    }

    send("Rays updated\n\n");

    int color[16] = {0, 0, 0, 0,
                     0, 0, 0, 0,
                     0, 0, 0, 0,
                     0, 0, 0, 0};

    while (1) {
        for (uint8_t beam_idx = 0; beam_idx < NUM_BEAMS; beam_idx++) {
            incr_beam_hue(ray_list->rays[0]->beams[beam_idx], 1);
            /*
            switch(color[beam_idx]) {
                case 0:
                    if (incr_beam_red(ray_list->rays[0]->beams[beam_idx])){
                        color[beam_idx] = (color[beam_idx]+1) % 3;
                    }
                    break;
                case 1:
                    if (incr_beam_green(ray_list->rays[0]->beams[beam_idx])) {
                        color[beam_idx] = (color[beam_idx]+1) % 3;
                    }
                    break;
                case 2:
                default:
                    if (incr_beam_blue(ray_list->rays[0]->beams[beam_idx])) {
                        color[beam_idx] = (color[beam_idx]+1) % 3;
                    }
            }
             */
        }
        update_ray(ray_list->rays[0]);
    }
}
