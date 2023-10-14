#include <Adafruit_Circuit_Playground.h>
#include "utils/Color.h"
#include "utils/Pixel.h"
#include "utils/Ticker.h"
#include "Chaser.h"


Chaser::Chaser(unsigned long stepMsIn)
  : StepTicker(stepMsIn), PixelStrip() {
}

void Chaser::update() {
  if (!this->shouldUpdate()) {
    return;
  }
  this->pixels[this->i]->scaleBrightness(0.0);
  this->i++;
  if (this->i == this->pixels.size()) {
    this->i = 0;
  }
  this->pixels[this->i]->scaleBrightness(1.0);
  this->increment();
}