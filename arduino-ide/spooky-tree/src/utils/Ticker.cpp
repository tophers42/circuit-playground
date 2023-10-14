#include <Arduino.h>
#include "Ticker.h"

void Ticker::begin() {}

void Ticker::update() {}

bool Ticker::shouldUpdate() {
  return millis() >= this->nextUpdateMs;
}

StepTicker::StepTicker(unsigned long stepMsIn) 
  : stepMs(stepMsIn) {}

StepTicker::StepTicker(unsigned long cycleTimeMs, int numSteps) {
  this->stepMs = cycleTimeMs / long(numSteps);
}

void StepTicker::increment() {
   this->nextUpdateMs = millis() + this->stepMs;
}
