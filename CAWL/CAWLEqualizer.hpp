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
    CAWLLowShelfFilter cLowShelf;       //For low end shelving
    CAWLHighShelfFilter cHighShelf;     //For high end shelving
    CAWLPeakFilter cLowMid;             //Peak for low mid
    CAWLPeakFilter cHighMid;            //Peak for high mid
    
    double cLowShelfCenterFreq;         //Low shelf center frequency
    double cHighShelfCenterFreq;        //High shelf center frequency
    double cLowMidCenterFreq;           //Low mid center frequency
    double cHighMidCenterFreq;          //High mid center frequency
    double cLowMidQFactor;              //Low mid Peak filter Q value
    double cHighMidQFactor;             //High mid Peak filter Q value
};

#endif /* CAWLEqualizer_hpp */
