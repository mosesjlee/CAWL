//
//  CAWLIIRCombFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLIIRCombFilter.hpp"

CAWLIIRCombFilter::CAWLIIRCombFilter()
{
    mGain = 0.5;
    mMixLevel = 0.5;
}

CAWLIIRCombFilter::~CAWLIIRCombFilter()
{
    
}

void CAWLIIRCombFilter::processBuffer(float *buf, const unsigned int numSamples)
{
    float yCurrOutput = 0.0;
    float xCurrSample = 0.0;
    float zSample = 0.0;
    for(unsigned i = 0; i < numSamples; i++)
    {
        xCurrSample = buf[i] *mMixLevel;
        zSample = mGain * delayLine.processNextSample(yCurrOutput);
        yCurrOutput = xCurrSample + zSample;
        
        buf[i] = yCurrOutput;
    }
}
