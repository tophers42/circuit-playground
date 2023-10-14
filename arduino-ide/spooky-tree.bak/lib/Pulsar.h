//
// Created by Christoph Neyer on 9/10/22.
//

#ifndef CIRCUIT_PLAYGROUND_EXPRESS_PULSAR_H
#define CIRCUIT_PLAYGROUND_EXPRESS_PULSAR_H

#include <vector>
#include <string>
#include <Arduino.h>
#include <Adafruit_Circuit_Playground.h>
#include "Pixel.h"


class Pulsar {
    unsigned long nextUpdateTimeMs;
    std::vector<Pixel> pixels;
    unsigned long stepTimeMs;
    float_t direction;
    float_t stepSize;
    float_t scaleFactor;
public:
    Pulsar(unsigned long cycleTimeMs, int numSteps);

    void addPixel(uint16_t n, Adafruit_CPlay_NeoPixel *strip, uint32_t color);

    bool shouldUpdate();


    void update();
};

#endif //CIRCUIT_PLAYGROUND_EXPRESS_PULSAR_H

