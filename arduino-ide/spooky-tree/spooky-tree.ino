#include <Adafruit_CircuitPlayground.h>
#include "src/Chaser.h"
#include "src/utils/Color.h"
#include "src/Pulsar.h"
#include "src/utils/Ticker.h"
#include "src/Detector.h"
#include "src/Tree.h"
#include "src/Wave.h"

#define LEFT_EYE_PIN A7
#define RIGHT_EYE_PIN A1
// #define LEAVES_PIN CPLAY_NEOPIXELPIN
#define LEAVES_PIN A4
#define DETECTOR_READ_PIN A10
#define DETECTOR_WRITE_PIN CPLAY_IR_EMITTER

Tree spookyTree = Tree(LEFT_EYE_PIN, RIGHT_EYE_PIN, LEAVES_PIN, DETECTOR_READ_PIN, DETECTOR_WRITE_PIN);


void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.speaker.off();
  analogReadResolution(12);
  Serial.begin(9600);
  delay(1000);
  Serial.println("setup");
  spookyTree.begin();
}

void loop() {
  spookyTree.update();
}