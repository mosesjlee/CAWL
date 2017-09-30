//
//  CAWLFIRCombFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLFIRCombFilter.hpp"
CAWLFIRCombFilter::CAWLFIRCombFilter()
{
    mGain = 1.0;
}

CAWLFIRCombFilter::~CAWLFIRCombFilter()
{
    
}

void CAWLFIRCombFilter::processBuffer(float * buf, const unsigned int numSamples)
{
    float yCurrSample = 0.0;
    for(unsigned int i = 0; i < numSamples; i++)
    {
        float xCurrSample = buf[i];
        float zCurrSample = delayLine.processNextSample(xCurrSample);
        yCurrSample = zCurrSample * mGain + xCurrSample;
        buf[i] = yCurrSample;
    }
}
    

