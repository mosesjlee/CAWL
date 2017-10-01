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
    mGain = .4;
    mMixLevel = .9;
    lastSampleOfBlock = 0.0;
    delayLine.setDelayTime(50);
}

CAWLIIRCombFilter::~CAWLIIRCombFilter()
{
    
}

//void CAWLIIRCombFilter::setDelay(unsigned int delay)
//{
//    delayLine.setDelayTime(delay);
//}

void CAWLIIRCombFilter::processBuffer(float *buf, const unsigned int numSamples)
{
    float yCurrOutput = lastSampleOfBlock;
    float xCurrSample = 0.0;
    float zSample = 0.0;
    for(unsigned i = 0; i < numSamples; i++)
    {
        xCurrSample = buf[i] *mMixLevel;
        zSample = mGain * delayLine.processNextSample(yCurrOutput);
        yCurrOutput = xCurrSample + zSample;

        if(yCurrOutput > 1.0)
            yCurrOutput = 1.0;
        else if(yCurrOutput < -1.0)
            yCurrOutput = -1.0;
        
        buf[i] = yCurrOutput;
    }
    lastSampleOfBlock = yCurrOutput;
}
