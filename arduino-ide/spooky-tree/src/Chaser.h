#ifndef CIRCUIT_PLAYGROUND_EXPRESS_CHASER_H
#define CIRCUIT_PLAYGROUND_EXPRESS_CHASER_H

#include <vector>
#include <Arduino.h>
#include <Adafruit_Circuit_Playground.h>
#include "utils/Ticker.h"
#include "utils/Pixel.h"


class Chaser : public StepTicker, public PixelStrip {
  float_t direction = 1;
  uint8_t i = 0;
public:
  explicit Chaser(unsigned long stepMsIn);
  void update() override;
};

#endif  //CIRCUIT_PLAYGROUND_EXPRESS_CHASER_H