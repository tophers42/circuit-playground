#include <Adafruit_Circuit_Playground.h>
#include "utils/Color.h"
#include "utils/Pixel.h"
#include "Pulsar.h"



Pulsar::Pulsar(unsigned long cycleTimeMs, int numSteps)
  : StepTicker(cycleTimeMs, numSteps), PixelStrip() {
  this->direction = -1;
  this->stepSize = 1 / float(numSteps);
  this->scaleFactor = 1;
}


void Pulsar::update() {
  Serial.print("updating. next update at: ");
  Serial.print(this->nextUpdateMs);
  Serial.print("\n");
  Serial.print("millis: ");
  Serial.print(millis());
  Serial.print("\n");
  if (!shouldUpdate()) {
    return;
  }
  this->nextUpdateMs = millis() + (this->stepMs);
  Serial.print("next update time: ");
  Serial.print(this->nextUpdateMs);
  Serial.print("\n");
  float_t targetScale = this->scaleFactor + (this->direction * this->stepSize);
  if (targetScale > 1) {
    targetScale = 1;
    this->direction = -1;
  } else if (targetScale < 0) {
    targetScale = 0;
    this->direction = 1;
  }
  this->scaleFactor = targetScale;
  for (Pixel *i : this->pixels) {
    Serial.print("setting brightness\n");
    Serial.print(i->n);
    Serial.print("\n");
    Serial.print(this->scaleFactor);
    Serial.print("\n");
    i->scaleBrightness(this->scaleFactor);
  }
}