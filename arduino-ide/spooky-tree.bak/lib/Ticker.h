
#ifndef CIRCUIT_PLAYGROUND_EXPRESS_TICKER_H
#define CIRCUIT_PLAYGROUND_EXPRESS_TICKER_H

class Ticker {
public:
  unsigned long nextUpdateMs = 0;

  void shouldUpdate();
}

class StepTicker : public Ticker {
  unsigned long stepMs;
public:
  StepTicker(unsigned long stepMsIn);
  void increment();
}

#endif //CIRCUIT_PLAYGROUND_EXPRESS_TICKER_H
