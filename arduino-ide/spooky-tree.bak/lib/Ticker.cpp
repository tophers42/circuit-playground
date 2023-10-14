#include "Ticker.h"

void Ticker::shouldUpdate() {
  return millis() >= nextUpdateMs;
}

StepTicker::StepTicker(unsigned long stepMsIn) {
  this->stepMs = stepMsIn;
}

void StepTicker::increment() {
  this->nextUpdateMs += this->stepMs;
}