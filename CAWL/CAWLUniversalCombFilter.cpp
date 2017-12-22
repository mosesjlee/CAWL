//
//  CAWLUniversalCombFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 9/30/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLUniversalCombFilter.hpp"

/*
 Constructor. Set everything to default
 and initialize the delay line
 */
CAWLUniversalCombFilter::CAWLUniversalCombFilter()
{
    cLastSampleOfBlock = 0.0;
    cFeedbackGain = 1.0;
    cMixLevel = 1.0;
    cFeedForwardGain = 0.0;
    cDelayLine = new CAWLDelayLine();
}

/*
 Destructor
 */
CAWLUniversalCombFilter::~CAWLUniversalCombFilter()
{
    delete cDelayLine;
}

/*
 Main processing block
 @param audioStreambuf the buffer of audio stream in 32 bit float
 @param numSamples the number of samples in the buffer block
 */
void CAWLUniversalCombFilter::processBuffer(float * audioStreambuf, const unsigned int numSamples)
{
    double yCurrSample = 0.0;
    double xCurrSample = 0.0;
    double xHCurrSample = 0.0;
    double zDelayedSample = cLastSampleOfBlock;
    for(unsigned i = 0; i < numSamples; i++)
    {
        xCurrSample = audioStreambuf[i];
		xHCurrSample = xCurrSample + zDelayedSample * cFeedbackGain;
        zDelayedSample = cDelayLine->processNextSample(xHCurrSample);
        yCurrSample = zDelayedSample * cFeedForwardGain + xHCurrSample * cMixLevel;
        audioStreambuf[i] = yCurrSample + xCurrSample * cDryMix;
    }
    cLastSampleOfBlock = zDelayedSample;
}

/*
 Sets the dry mix. This is used for delay effects
 @param newDryMix -> the new dry mix level
 */
void CAWLUniversalCombFilter::setDryMix(double newDryMix)
{
    if(newDryMix > 1.0) cDryMix = 1.0;
    else if(newDryMix < 0.0) cDryMix = 0.0;
    else cDryMix = newDryMix;
}



