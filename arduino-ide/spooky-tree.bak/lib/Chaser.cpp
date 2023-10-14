//
// Created by Christoph Neyer on 9/10/22.
//
#include <string>
#include <Adafruit_Circuit_Playground.h>
#include "Color.h"
#include "Pixel.h"
#include "Ticker.h"
#include "Chaser.h"



Chaser::Chaser(unsigned long stepTimeMs) {
  this->ticker = StepTicker()
    this->nextUpdateTimeMs = 0;
    this->stepTimeMs = cycleTimeMs / long(numSteps);
    this->direction = -1;
    this->stepSize = 1 / float(numSteps);
    this->scaleFactor = 1;
}

void Pulsar::addPixel(uint16_t n, Adafruit_CPlay_NeoPixel *strip, uint32_t color) {
    pixels.emplace_back(n, strip, color);
}

bool Pulsar::shouldUpdate() {
    return this->nextUpdateTimeMs == 0 || this->nextUpdateTimeMs < millis();
}


void Pulsar::update() {
    Serial.print("updating. next update at: ");
    Serial.print(this->nextUpdateTimeMs);
    Serial.print("\n");
    Serial.print("millis: ");
    Serial.print(millis());
    Serial.print("\n");
    if (!shouldUpdate()) {
        return;
    }
    this->nextUpdateTimeMs = millis() + (this->stepTimeMs);
    Serial.print("next update time: ");
    Serial.print(this->nextUpdateTimeMs);
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
    for (Pixel i: this->pixels) {
        Serial.print("setting brightness\n");
        Serial.print(i.n);
        Serial.print("\n");
        Serial.print(this->scaleFactor);
        Serial.print("\n");
        i.scaleBrightness(this->scaleFactor);
    }
}