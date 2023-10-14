#ifndef CIRCUIT_PLAYGROUND_EXPRESS_TICKER_H
#define CIRCUIT_PLAYGROUND_EXPRESS_TICKER_H

class Ticker {
protected:
   unsigned long nextUpdateMs = 0;
public:
  virtual void begin();
  bool shouldUpdate();
  virtual void update();
};


class StepTicker: public Ticker {
protected:
  unsigned long stepMs = 100;
public:
  explicit StepTicker(unsigned long stepMsIn);
  StepTicker(unsigned long cycleTimeMs, int numSteps);
  void increment();
};

#endif  //CIRCUIT_PLAYGROUND_EXPRESS_TICKER_H