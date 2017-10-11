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
    mFeedbackGain = 1.0;
    mMixLevel = 1;
    lastSampleOfBlock = 0.0;
    delayLine.setDelayTimeInMilliseconds(100);
}

CAWLIIRCombFilter::~CAWLIIRCombFilter()
{
    
}

void CAWLIIRCombFilter::processBuffer(float *buf, const unsigned int numSamples)
{
    float yCurrOutput = lastSampleOfBlock;
    float xCurrSample = 0.0;
    float zSample = 0.0;
    for(unsigned i = 0; i < numSamples; i++)
    {
        xCurrSample = buf[i] *mMixLevel;
        zSample = mFeedbackGain * delayLine.processNextSample(yCurrOutput);
        yCurrOutput = xCurrSample + zSample;

        if(yCurrOutput > 1.0)
            yCurrOutput = 1.0;
        else if(yCurrOutput < -1.0)
            yCurrOutput = -1.0;
        
        buf[i] = yCurrOutput;
    }
    lastSampleOfBlock = yCurrOutput;
}
