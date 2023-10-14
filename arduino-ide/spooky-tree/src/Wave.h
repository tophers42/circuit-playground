#ifndef CIRCUIT_PLAYGROUND_EXPRESS_WAVE_H
#define CIRCUIT_PLAYGROUND_EXPRESS_WAVE_H
#include "utils/Ticker.h"
#include "utils/Pixel.h"

class Wave : public StepTicker, public PixelStrip {
  int currentStep = 0;
  int totalSteps = 100;
  int offsetSize = 50;

  float_t getScale(int step);
public:
  explicit Wave(unsigned long stepMsIn);
  void update() override;
};


#endif  //CIRCUIT_PLAYGROUND_EXPRESS_WAVE_H