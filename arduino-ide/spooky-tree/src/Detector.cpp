#include "Detector.h"

Detector::Detector(int readPinIn, int writePinIn, int thresholdIn, int sampleRateMsIn) {
  this->readPin = readPinIn;
  this->writePin = writePinIn;
  this->threshold = thresholdIn;
  this->sampleTicker = new StepTicker(sampleRateMsIn);
  this->movingAvg = new MovingAvg(10);
}

void Detector::begin() {
  pinMode(this->writePin, OUTPUT);
  digitalWrite(this->writePin, LOW);
}

void Detector::record() {
  digitalWrite(this->writePin, HIGH);
  delayMicroseconds(200);
  digitalWrite(this->writePin, LOW);
  int reading = analogRead(this->readPin);
  this->movingAvg->addReading(reading);
}


void Detector::update() {
  if (!this->sampleTicker->shouldUpdate()) {
    return;
  }
  this->record();
  if (this->movingAvg->avg > this->threshold) {
    this->isSet = true;
  } else {
    this->isSet = false;
  }
}