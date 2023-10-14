//
// Created by Christoph Neyer on 9/10/22.
//

#ifndef CIRCUIT_PLAYGROUND_EXPRESS_COLOR_H
#define CIRCUIT_PLAYGROUND_EXPRESS_COLOR_H

#include <Adafruit_Circuit_Playground.h>

uint8_t unpackW(uint32_t packed);

uint8_t unpackR(uint32_t packed);

uint8_t unpackG(uint32_t packed);

uint8_t unpackB(uint32_t packed);

uint32_t scaleColorBrightness(uint32_t packed, float_t scaleFactor);

static const uint32_t WHITE = Adafruit_CPlay_NeoPixel::Color(255, 255, 255);
static const uint32_t RED = Adafruit_CPlay_NeoPixel::Color(255, 0, 0);
static const uint32_t GREEN = Adafruit_CPlay_NeoPixel::Color(0, 255, 0);
static const uint32_t BLUE = Adafruit_CPlay_NeoPixel::Color(0, 0, 255);


#endif  //CIRCUIT_PLAYGROUND_EXPRESS_COLOR_H