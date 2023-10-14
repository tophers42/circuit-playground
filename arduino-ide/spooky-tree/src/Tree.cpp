#include <Adafruit_Circuit_Playground.h>
#include "Tree.h"
#include "Detector.h"
#include "Wave.h"
#include "utils/Color.h"

uint32_t grbwGreen = Adafruit_CPlay_NeoPixel::Color(255, 0, 0, 0);
uint32_t grbwWhite = Adafruit_CPlay_NeoPixel::Color(255, 255, 255, 255);
uint32_t eyeColor = grbwGreen;

uint32_t leafColor = GREEN;

// LEAVES
TreeLeaves::TreeLeaves(int leavesPin) {
  this->strip = new Adafruit_CPlay_NeoPixel(3, leavesPin);
  this->wave = new Wave(50);
}

void TreeLeaves::begin() {
  this->strip->begin();
  for (int i = 0; i < 3; i++) {
    this->wave->addPixel(i, this->strip, leafColor);
  }
  this->strip->clear();
}

void TreeLeaves::update() {
  this->wave->update();
  this->strip->show();
}

void TreeLeaves::clear() {
  this->strip->clear();
  this->strip->show();
}

// EYES
TreeEye::TreeEye(int eyePin) {
  this->strip = new Adafruit_CPlay_NeoPixel(7, eyePin, NEO_RGBW + NEO_KHZ800);
  this->wave = new Wave(50);
}

void TreeEye::begin() {
  this->strip->begin();
  for (int i = 1; i < 7; i++) {
    this->wave->addPixel(i, this->strip, eyeColor);
  }
  this->strip->clear();
}

void TreeEye::update() {
  this->wave->update();
  this->strip->show();
}

void TreeEye::clear() {
  this->strip->clear();
  this->strip->show();
}

// TRUNK
Tree::Tree(int leftEyePin, int rightEyePin, int leavesPin, int detectorReadPin, int detectorWritePin) {
  this->detector = new Detector(detectorReadPin, detectorWritePin, 1200, 10);
  this->leftEye = new TreeEye(leftEyePin);
  this->rightEye = new TreeEye(rightEyePin);
  this->leaves = new TreeLeaves(leavesPin);
}

void Tree::begin() {
  this->detector->begin();
  this->leftEye->begin();
  this->rightEye->begin();
  this->leaves->begin();
}

void Tree::updateDisplay() {
  this->leftEye->update();
  this->rightEye->update();
  this->leaves->update();
}

void Tree::clearDisplay() {
  this->leftEye->clear();
  this->rightEye->clear();
  this->leaves->clear();
}

bool Tree::isDisplaying() {
  return this->setAtMs != 0 && millis() < (this->setAtMs + this->displayMs);
}

void Tree::update() {
  this->detector->update();
  if (this->isDisplaying()) {
    this->updateDisplay();
    return;
  }
  if (this->detector->isSet) {
    CircuitPlayground.redLED(true);
    this->setAtMs = millis();
  } else {
    CircuitPlayground.redLED(false);
    this->clearDisplay();
  }
}