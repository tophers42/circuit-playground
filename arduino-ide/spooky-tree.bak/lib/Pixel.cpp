//
// Created by Christoph Neyer on 9/10/22.
//

#include <Arduino.h>
#include <Adafruit_Circuit_Playground.h>
#include "Color.h"
#include "Pixel.h"

Pixel::Pixel(uint16_t nIn, Adafruit_CPlay_NeoPixel *stripIn, uint32_t maxColorIn) : n(nIn), strip(stripIn),
                                                                                    maxColor(maxColorIn) {}

void Pixel::scaleBrightness(float_t scaleFactor) const {
    uint32_t scaled = scaleColorBrightness(this->maxColor, scaleFactor);
    Serial.print("setting pixel color: ");
    Serial.print(this->n);
    Serial.print("\n");
    Serial.print(scaled);
    Serial.print("\n");
    this->strip->setPixelColor(this->n, scaled);
}