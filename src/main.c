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

    ray_t *ray = create_ray(81, 82, 83);

    send("Ray created\n");

    ray->size = 16;
    for (uint8_t i = 0; i < NUM_BEAMS; i++) {
        set_beam_rgb(ray, i, 127, 0, 255);
    }
    update_ray(ray);

    send("Ray updated\n\n");

    while (1) {

    }
}
