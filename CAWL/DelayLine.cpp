#include <iostream>
#include "delayl.h"

using std::cout;
using std::endl;

DelayLine::DelayLine()
{
  maxDelay = 4096;
  buffer = new double [maxDelay+1];
  for (int i=0; i<maxDelay+1; i++) buffer[i] = 0.0;
  currDelay = maxDelay;
  currIndex = 0;
}

DelayLine::DelayLine(int size)
{
  maxDelay = size;
  buffer = new double [maxDelay+1];
  for (int i=0; i<maxDelay+1; i++) buffer[i] = 0.0;
  currDelay = maxDelay;
  currIndex = 0;
}

DelayLine::~DelayLine()
{
  delete [] buffer;
}

void DelayLine::setDelayLineDelay(double newDelay)
{
  if (newDelay > (double) maxDelay) {
    cout << "Error: setting delay greater than max delay...\n";
    return;
  }
  else {
    currDelay = newDelay;
  }
}

double DelayLine::getDelayLineDelay()
{
  return currDelay;
}

double DelayLine::getCurrentOut()
{
  double delayIndex;
  double output;

  delayIndex = currIndex - currDelay;
  if (delayIndex < 0.0)
    delayIndex = delayIndex + ((double) maxDelay + 1.0);
    
  if (delayIndex > (double) maxDelay) {
    output = buffer[(int) delayIndex] + (buffer[0] - 
							buffer[(int) delayIndex]) * (delayIndex -
							(double) ((int) delayIndex));
  }
  else {
    output = buffer[(int) delayIndex] + (buffer[(int) delayIndex + 1] - 
							buffer[(int) delayIndex]) * (delayIndex - (double) ((int) delayIndex));
  }

  if (output > 1.0)
    output = 1.0;
  else if (output < -1.0)
    output = -1.0;

  return output;
}

double DelayLine::tick(double input)
{
  double output;
 
  buffer[currIndex] = input;
  output = getCurrentOut();

  currIndex = (currIndex + 1) % (maxDelay + 1);
  return output;
  
}

