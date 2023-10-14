#ifndef CIRCUIT_PLAYGROUND_EXPRESS_DETECTOR_H
#define CIRCUIT_PLAYGROUND_EXPRESS_DETECTOR_H

#include <Adafruit_CircuitPlayground.h>
#include "utils/MovingAvg.h"
#include "utils/Ticker.h"

class Detector {
  MovingAvg *movingAvg;
  int readPin;
  int writePin;
  int threshold;
  StepTicker *sampleTicker;
  void record();
public:
  bool isSet;
  Detector(int readPinIn, int writePinIn, int thresholdIn, int sampleRateMsIn);

  void begin();
  void update();
};
#endif  // CIRCUIT_PLAYGROUND_EXPRESS_DETECTOR_H