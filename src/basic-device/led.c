//
// Created by Garth Webb on 3/13/18.
//

#include <stdlib.h>
#include "led.h"
#include "../lib/serial.h"

led_collection_t* create_led_collection(device_list_t *devices) {
    led_collection_t* leds = (led_collection_t *) malloc(sizeof(led_collection_t));
    if (!leds) {
        DEBUG("E: malloc failed for led_collection_t\n");
        return NULL;
    }

    send_int("I: devices->length %d\n", devices->length);
    leds->length = NUM_LED_VALUES * (devices->length / 3);
    send_int("I: leds->length %d\n", leds->length);
    leds->list = (led_t **) malloc(sizeof(led_t *) * leds->length);
    if (!leds->list) {
        DEBUG("E: malloc failed for led_t*\n");
        return NULL;
    }

    device_t *red_device;
    device_t *green_device;
    device_t *blue_device;
    led_t *led;

    for (uint8_t device_idx = 0; device_idx < devices->length; device_idx += 3) {
        red_device = devices->list[device_idx];
        green_device = devices->list[device_idx+1];
        blue_device = devices->list[device_idx+2];

        for (uint8_t led_idx = 0; led_idx < NUM_LED_VALUES; led_idx++) {
            led = (led_t *) malloc(sizeof(led_t));
            send_int("I: led %d\n", led_idx);
            if (!led) {
                DEBUG("E: malloc failed for led_t\n");
                break;
            }

            led->red = &(red_device->value[led_idx]);
            led->green = &(green_device->value[led_idx]);
            led->blue = &(blue_device->value[led_idx]);

            led->hue = 0;
            led->value = 1.0;
            led->saturation = 1.0;

            leds->list[led_idx + device_idx * NUM_LED_VALUES] = led;
        }
    }

    return leds;
}
