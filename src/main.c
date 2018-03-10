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
        set_beam_rgb(ray, i, 0, 0, 128);
    }
    update_ray(ray);

    send("Ray updated\n\n");

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
