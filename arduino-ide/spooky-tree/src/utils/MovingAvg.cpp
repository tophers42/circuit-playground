#include "MovingAvg.h"


MovingAvg::MovingAvg(int countIn) {
 this->count = countIn;
 this->readings = new int[countIn];
}

void MovingAvg::addReading(int reading) {
  if (this->numReadings == count) {
    this->sum -= this->readings[this->next];
  } else {
    this->numReadings++;
  }
  this->readings[this->next] = reading;
  this->sum += reading;
  this->avg = sum / this->numReadings;
  this->next++;
  if (this->next == count) {
    this->next = 0;
  }
}

void MovingAvg::reset() {
  this->avg = 0;
  this->next = 0;
  this->numReadings = 0;
  this->sum = 0;
}