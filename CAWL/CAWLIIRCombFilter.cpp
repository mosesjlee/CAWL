//
//  CAWLIIRCombFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLIIRCombFilter.hpp"

/*
 Constructor. Set everything to default
 Initialize delay line
 */
CAWLIIRCombFilter::CAWLIIRCombFilter()
{
    cFeedbackGain = 0.0;
    cMixLevel = 1;
    cLastSampleOfBlock = 0.0;
    cDelayLine = new CAWLDelayLine();
    cDelayLine->setDelayTimeInMilliseconds(0);
}

/*
 Destructor
 */
CAWLIIRCombFilter::~CAWLIIRCombFilter()
{
    delete cDelayLine;
}

/*
 Main processing block
 @param audioStreambuf the buffer of audio stream in 32 bit float
 @param numSamples the number of samples in the buffer block
 */
void CAWLIIRCombFilter::processBuffer(float *audioStreambuf, const unsigned int numSamples)
{
    double yCurrOutput = cLastSampleOfBlock;
    double xCurrSample = 0.0;
    double zSample = 0.0;
    for(unsigned i = 0; i < numSamples; i++)
    {
        xCurrSample = audioStreambuf[i] *cMixLevel;
        zSample = cFeedbackGain * cDelayLine->processNextSample(yCurrOutput);
        yCurrOutput = xCurrSample + zSample;

        if(yCurrOutput > 1.0)
            yCurrOutput = 1.0;
        else if(yCurrOutput < -1.0)
            yCurrOutput = -1.0;
        
        audioStreambuf[i] = yCurrOutput;
    }
    cLastSampleOfBlock = yCurrOutput;
}
