/*
 CAWLDelayLine.hpp
 CAWL

 Created by Moses Lee on 9/17/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLDelayLine class. A delay line buffer to delay samples.
*/

#ifndef CAWLDelayLine_hpp
#define CAWLDelayLine_hpp
#define MAX_DELAY_IN_SAMPLES 44100 * 1

#include "CAWLSoundModule.hpp"
class CAWLDelayLine
{
public:
    CAWLDelayLine();
    ~CAWLDelayLine();
    void setDelayTimeInMilliseconds(float delayTime);
    void setDelayTimeInSamples(float delaySamples);
    double processNextSample(double currSample);
    
private:
    inline double linearInterp(float x1, float y1, float x2, float y2, float frac);

    double          *cDelayLine;
    float           cCurrWritePos;
    double          cCurrDelayInSamples;
    unsigned int    cMaxDelayInSamples;
};
#endif /* CAWLDelayLine_hpp */
