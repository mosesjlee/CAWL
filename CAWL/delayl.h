#ifndef DELAYL_H
#define DELAYL_H

class DelayLine {
 public:
  DelayLine();
  DelayLine(int);
  ~DelayLine();
  void setDelayLineDelay(double);
  double getDelayLineDelay();
  double getCurrentOut();
  double tick(double);

 private:
  double *buffer;
  int maxDelay;
  double currDelay;
  int currIndex;
};

#endif
