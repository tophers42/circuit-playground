#ifndef CIRCUIT_PLAYGROUND_EXPRESS_PULSAR_H
#define CIRCUIT_PLAYGROUND_EXPRESS_PULSAR_H

#include <vector>
#include <string>
#include <Arduino.h>
#include <Adafruit_Circuit_Playground.h>
#include "utils/Pixel.h"
#include "utils/Ticker.h"


class Pulsar : public StepTicker, public PixelStrip {
  float_t direction;
  float_t stepSize;
  float_t scaleFactor;
public:
  Pulsar(unsigned long cycleTimeMs, int numSteps);
  void update() override;
};

#endif  //CIRCUIT_PLAYGROUND_EXPRESS_PULSAR_H