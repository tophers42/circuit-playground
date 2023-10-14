#ifndef CIRCUIT_PLAYGROUND_EXPRESS_TREE_H
#define CIRCUIT_PLAYGROUND_EXPRESS_TREE_H

#include <Adafruit_CircuitPlayground.h>
#include "Wave.h"
#include "Detector.h"

class TreeEye {
  Adafruit_CPlay_NeoPixel *strip;
  Wave *wave;
public:
  explicit TreeEye(int eyePin);
  void begin();
  void update();
  void clear();
};

class TreeLeaves {
  Adafruit_CPlay_NeoPixel *strip;
  Wave *wave;
public:
  explicit TreeLeaves(int leavesPin);
  void begin();
  void update();
  void clear();
};

class Tree {

  TreeEye *rightEye;
  TreeEye *leftEye;
  TreeLeaves *leaves;
  Detector *detector;
  int setAtMs = 0;
  int displayMs = 15 * 1000;

  bool isDisplaying();
  void clearDisplay();
  void updateDisplay();

public:
  Tree(int leftEyePin, int rightEyePin, int leavesPin, int detectorReadPin, int detectorWritePin);
  void begin();
  void update();
  void clear();
};

#endif  //CIRCUIT_PLAYGROUND_EXPRESS_TREE_H