//
// Created by Christoph Neyer on 9/3/22.
//

#include <Arduino.h>
#include <Adafruit_Circuit_Playground.h>
#include "Color.h"

uint8_t unpackW(uint32_t packed) {
  return (uint8_t)(packed >> 24);
}

uint8_t unpackR(uint32_t packed) {
  return (uint8_t)(packed >> 16);
}

uint8_t unpackG(uint32_t packed) {
  return (uint8_t)(packed >> 8);
}


uint8_t unpackB(uint32_t packed) {
  return (uint8_t)(packed);
}





uint32_t scaleColorBrightness(uint32_t packed, float_t scaleFactor) {
  uint8_t uR = unpackR(packed), uG = unpackG(packed), uB = unpackB(packed);
  return Adafruit_CPlay_NeoPixel::Color(uint8_t((float)uR * scaleFactor), uint8_t((float)uG * scaleFactor),
                                        uint8_t((float)uB * scaleFactor));
}