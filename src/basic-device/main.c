//
// Created by Garth Webb on 3/8/18.
//

#include "main.h"
#include "led.h"
#include "../lib/i2c_master.h"
#include "../lib/serial.h"

void init() {
    init_serial();
    i2c_init();
}

int main() {
    init();

    send("Init complete\n");

    device_list_t *devices = create_device_list();
    if (devices) {
        send_int("Found %d devices\n", devices->length);
    } else {
        DEBUG("E: create_device_list failed");
    }

    led_collection_t *leds = create_led_collection(devices);

    for (uint8_t i = 0; i < leds->length; i++) {
        DEBUG("meep?\n");
        *(leds->list[i]->red) = 128;
        *(leds->list[i]->green) = 0;
        *(leds->list[i]->blue) = 255;
    }

    send_int("I: list[0]->red: %d\n", *(leds->list[0]->red));
    send_int("I: device: %d\n", devices->list[0]->value[0]);

    update_devices(devices);

    while (1) {
    }
}
