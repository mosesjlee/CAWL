//
//  CAWLFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 9/30/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLCombFilter.hpp"

void CAWLCombFilter::setDelay(float delay)
{
    delayLine.setDelayTime(delay);
}

void CAWLCombFilter::setFeedForwardGain(float newGain)
{
    if(newGain > 1.0)
        newGain = 1.0;
    if(newGain < 0.0)
        newGain = 0.0;
    
    mFeedForwardGain = newGain;
}

void CAWLCombFilter::setFeedbackGain(float newGain)
{
    if(newGain > 1.0)
        newGain = 1.0;
    if(newGain < 0.0)
        newGain = 0.0;
    mFeedbackGain = newGain;
}

void CAWLCombFilter::setMixLevel(float newMixLevel)
{
    if(newMixLevel > 1.0)
        newMixLevel = 1.0;
    if(newMixLevel < 0.0)
        newMixLevel = 0.0;
    mMixLevel = newMixLevel;
}
