//
// Created by Garth Webb on 3/8/18.
//

#include <stdlib.h>
#include "beam.h"

beam_t* create_beam(uint8_t *red, uint8_t *green, uint8_t *blue) {
    beam_t *beam = (beam_t *) malloc(sizeof(beam_t));

    if (beam == NULL) {
        return NULL;
    }

    beam->red = red;
    beam->green = green;
    beam->blue = blue;

    return beam;
}

uint8_t incr_beam_red(beam_t *beam) {
    (*(beam->red))++;
    if (*(beam->red) == 0) {
        return 1;
    }
    return 0;
}

uint8_t incr_beam_green(beam_t *beam) {
    (*(beam->green))++;
    if (*(beam->green) == 0) {
        return 1;
    }
    return 0;
}

uint8_t incr_beam_blue(beam_t *beam) {
    (*(beam->blue))++;
    if (*(beam->blue) == 0) {
        return 1;
    }
    return 0;
}

void incr_beam_hue(beam_t *beam, float amount) {
    beam->hue += amount;
    if (beam->hue > 360) {
        beam->hue -= 360;
    }

    copyHSVToRGB(beam);
}

void decr_beam_hue(beam_t *beam, float amount) {
    beam->hue -= amount;
    copyHSVToRGB(beam);
}

void copyHSVToRGB(beam_t *beam) {
    float r = 0, g = 0, b = 0;

    if (beam->saturation == 0) {
        r = beam->value;
        g = beam->value;
        b = beam->value;
    } else {
        int i;
        float f, p, q, t;

        if (beam->hue == 360)
            beam->hue = 0;
        else
            beam->hue /= 60;

        //i = (int)trunc(beam->hue);
        i = (int) beam->hue;
        f = beam->hue - i;

        p = beam->value * (1.0 - beam->saturation);
        q = beam->value * (1.0 - (beam->saturation * f));
        t = beam->value * (1.0 - (beam->saturation * (1.0 - f)));

        switch (i) {
            case 0:
                r = beam->value;
                g = t;
                b = p;
                break;

            case 1:
                r = q;
                g = beam->value;
                b = p;
                break;

            case 2:
                r = p;
                g = beam->value;
                b = t;
                break;

            case 3:
                r = p;
                g = q;
                b = beam->value;
                break;

            case 4:
                r = t;
                g = p;
                b = beam->value;
                break;

            default:
                r = beam->value;
                g = p;
                b = q;
                break;
        }
    }

    *(beam->red) = (uint8_t) r * 255;
    *(beam->green) = (uint8_t) g * 255;
    *(beam->blue) = (uint8_t) b * 255;
}