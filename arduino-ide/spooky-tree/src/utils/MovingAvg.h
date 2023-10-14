#ifndef CIRCUIT_PLAYGROUND_EXPRESS_MOVING_AVG_H
#define CIRCUIT_PLAYGROUND_EXPRESS_MOVING_AVG_H

class MovingAvg {
  int *readings;
  int numReadings = 0;
  int count;
  int sum = 0;
  int next = 0;
public:
  int avg;
  explicit MovingAvg(int countIn);
  void addReading(int reading);
  void reset();
};

#endif // CIRCUIT_PLAYGROUND_EXPRESS_MOVING_AVG_H
