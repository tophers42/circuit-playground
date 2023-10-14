#include <math.h>
#include "Wave.h"

#define PI 3.14159265359


Wave::Wave(unsigned long stepMsIn)
  : StepTicker(stepMsIn), PixelStrip() {
  this->currentStep = 0;
  this->totalSteps = 50;
  this->offsetSize = 2;
}

float_t Wave::getScale(int step) {
  double radians = ((double)step * 2 * PI) / (double)this->totalSteps;
  return ((float_t)(cos(radians) + 1) / 2) * .5;
}


void Wave::update() {
  if (!this->shouldUpdate()) {
    return;
  }

  for (int i = 0; i < this->pixels.size(); i++) {
    float_t scale = getScale(this->currentStep - (i * i * this->offsetSize));
    this->pixels[i]->scaleBrightness(scale);
  }

  this->currentStep++;
  if (this->currentStep > totalSteps) {
    this->currentStep = 0;
  }

  this->increment();
}