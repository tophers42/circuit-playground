#include <Adafruit_CircuitPlayground.h>

class Detector {
  uint16_t detectionThreshold;
  unsigned long sampleInterval;
  uint8_t sampleCount;
  std::vector<uint16_t> measurements;
  

}