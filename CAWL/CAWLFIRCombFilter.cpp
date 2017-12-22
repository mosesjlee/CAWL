//
//  CAWLFIRCombFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLFIRCombFilter.hpp"

/*
 Constructor. Set everything to default
 Initialize delay line
 */
CAWLFIRCombFilter::CAWLFIRCombFilter()
{
    cFeedForwardGain = 1.0;
    cLastSampleOfBlock = 0.0;
    cDelayLine = new CAWLDelayLine();
    cDelayLine->setDelayTimeInMilliseconds(0);
}
/*
 Destructor
 */
CAWLFIRCombFilter::~CAWLFIRCombFilter()
{
    delete cDelayLine;
}

/*
 Main processing block
 @param audioStreambuf the buffer of audio stream in 32 bit float
 @param numSamples the number of samples in the buffer block
 */
void CAWLFIRCombFilter::processBuffer(float * audioStreambuf, const unsigned int numSamples)
{
    float yCurrSample = cLastSampleOfBlock;
    for(unsigned int i = 0; i < numSamples; i++)
    {
        float xCurrSample = audioStreambuf[i];
        float zCurrSample = cDelayLine->processNextSample(xCurrSample);
        yCurrSample = zCurrSample * cFeedForwardGain + xCurrSample;
        audioStreambuf[i] = yCurrSample;
    }
    cLastSampleOfBlock = yCurrSample;
}
    

