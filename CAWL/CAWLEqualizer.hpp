//
//  CAWLEqualizer.hpp
//  CAWL
//
//  Created by Moses Lee on 10/12/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLEqualizer_hpp
#define CAWLEqualizer_hpp
#include "CAWLLowShelfFilter.hpp"
#include "CAWLHighShelfFilter.hpp"
#include "CAWLPeakFilter.hpp"

#include <stdio.h>
class CAWLEqualizer
{
public:
    CAWLEqualizer();
    ~CAWLEqualizer();
    void setLowShelfCenterFreq(double centerFreq);
    void setHighShelfCenterFreq(double centerFreq);
    void setlowMidCenterFreq(double centerFreq);
    void setHighMidCenterFreq(double centerFreq);
    void setLowShelfGain(double newGain);
    void setHighShelfGain(double newGain);
    void setlowMidGain(double newGain);
    void setHighMidGain(double newGain);
    void setLowMidQFactor(double newQFactor);
    void setHighMidQFactor(double newQFactor);
    void processBuffer(float * buf, const unsigned int numSamples);
private:
    CAWLLowShelfFilter lowShelf;
    CAWLHighShelfFilter highShelf;
    CAWLPeakFilter lowMid;
    CAWLPeakFilter highMid;
    double lowShelfCenterFreq, highShelfCenterFreq, lowMidCenterFreq, highMidCenterFreq;
    double lowMidQFactor, highMidQFactor;
};

#endif /* CAWLEqualizer_hpp */
