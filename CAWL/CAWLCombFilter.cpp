//
//  CAWLFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 9/30/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLCombFilter.hpp"

void CAWLCombFilter::setDelay(unsigned int delay)
{
    delayLine.setDelayTime(delay);
}

void CAWLCombFilter::setGain(float gain)
{
    mGain = gain;
}
