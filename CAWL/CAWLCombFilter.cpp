//
//  CAWLFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 9/30/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLCombFilter.hpp"
/*
 Sets the delay for the comb filter.
 Can be overridden
 @param delay -> the new delay time in milliseconds
 */
void CAWLCombFilter::setDelay(float delay)
{
    cDelayLine->setDelayTimeInMilliseconds(delay);
}

/*
 Sets the gain for any filters that use the
 feed forward gain
 @param newGain -> the new feed forward gain
 */
void CAWLCombFilter::setFeedForwardGain(float newGain)
{
    if(newGain > 1.0)
        newGain = 1.0;
    else if(newGain < 0.0)
        newGain = 0.0;
    else
        cFeedForwardGain = newGain;
}

/*
 Sets the gain for any filters that use the
 feed back gain
 @param newGain -> the new feed back gain
 */
void CAWLCombFilter::setFeedbackGain(float newGain)
{
    if(newGain > 1.0)
        newGain = 1.0;
    else if(newGain < 0.0)
        newGain = 0.0;
    else
        cFeedbackGain = newGain;
}

/*
 Sets the mix level for any filters between the
 original signal and the signal from the filter
 @param newMixLevel -> the new mix level
 */
void CAWLCombFilter::setMixLevel(float newMixLevel)
{
    if(newMixLevel > 1.0)
        newMixLevel = 1.0;
    else if(newMixLevel < 0.0)
        newMixLevel = 0.0;
    else
        cMixLevel = newMixLevel;
}
