//
// Created by Christoph Neyer on 9/10/22.
//

#include <Arduino.h>
#include <Adafruit_Circuit_Playground.h>
#include "Color.h"
#include "Pixel.h"

Pixel::Pixel(uint16_t nIn, Adafruit_CPlay_NeoPixel *stripIn, uint32_t maxColorIn)
  : n(nIn), strip(stripIn), maxColor(maxColorIn) {
}

void Pixel::scaleBrightness(float_t scaleFactor) const {
  uint32_t scaled = scaleColorBrightness(this->maxColor, scaleFactor);
  // Serial.println("scaling pixel color");
  // Serial.println("max");
  // Serial.println(this->maxColor);
  // Serial.println("n");
  // Serial.println(this->n);
  // Serial.println("scaled");
  // Serial.println(scaled);
  this->strip->setPixelColor(this->n, scaled);
}

void Pixel::setColor(uint32_t color) {
  this->strip->setPixelColor(this->n, color);
}

void PixelStrip::addPixel(uint16_t n, Adafruit_CPlay_NeoPixel *strip, uint32_t color) {
  this->pixels.emplace_back(new Pixel(n, strip, color));
}