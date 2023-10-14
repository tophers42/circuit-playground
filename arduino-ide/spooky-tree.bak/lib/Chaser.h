//
// Created by Christoph Neyer on 9/10/22.
//

#ifndef CIRCUIT_PLAYGROUND_EXPRESS_CHASER_H
#define CIRCUIT_PLAYGROUND_EXPRESS_CHASER_H

#include <vector>
#include <string>
#include <Arduino.h>
#include <Adafruit_Circuit_Playground.h>
#include "Ticker.h"
#include "Pixel.h"


class Chaser {
    Ticker ticker;
    std::vector<Pixel> pixels;
    float_t direction = 1;
public:
    Chaser(unsigned long stepTimeMs);

    void addPixel(uint16_t n, Adafruit_CPlay_NeoPixel *strip, uint32_t color);

    bool shouldUpdate();

    void update();
};

#endif //CIRCUIT_PLAYGROUND_EXPRESS_CHASER_H