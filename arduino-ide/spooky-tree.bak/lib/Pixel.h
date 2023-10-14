//
// Created by Christoph Neyer on 9/10/22.
//

#ifndef CIRCUIT_PLAYGROUND_EXPRESS_PIXEL_H
#define CIRCUIT_PLAYGROUND_EXPRESS_PIXEL_H

#include <Arduino.h>
#include <Adafruit_Circuit_Playground.h>

class Pixel {
public:
    uint16_t n;

    Adafruit_CPlay_NeoPixel *strip;
    uint32_t maxColor;

    Pixel(uint16_t nIn, Adafruit_CPlay_NeoPixel *stripIn, uint32_t maxColorIn);

    void scaleBrightness(float_t scaleFactor) const;

};

#endif //CIRCUIT_PLAYGROUND_EXPRESS_PIXEL_H

