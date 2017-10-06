//
//  CAWLLowShelfFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 10/5/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLLowShelfFilter.hpp"
CAWLLowShelfFilter::CAWLLowShelfFilter()
{
    mGain = 6.0;                //Start at 0
    centerFrequency = 100.0;    //In Hz
    calculateCoefficients();
}

CAWLLowShelfFilter::~CAWLLowShelfFilter()
{
    
}

void CAWLLowShelfFilter::calculateCoefficients()
{
    theta   = 2 * M_PI * centerFrequency/sampleRate;
    mu      = pow(10.0, (double) mGain/20.0);
    beta    = 4/(1.0 + mu);
    delta   = beta * tan(theta/2.0);
    gamma   = (1.0 - delta)/(1.0 + delta);
    a_0     = (1.0 - gamma)/2.0;
    a_1     = a_0;
    a_2     = 0.0;
    b_1     = -1 * gamma;
    b_2     = 0.0;
    c_0     = mu - 1.0;
    d_0     = .50;
}

void CAWLLowShelfFilter::setGain(float newGain)
{
    if(newGain > 12.0)
        newGain = 12.0;
    
    mGain = newGain;
}
void CAWLLowShelfFilter::setCutOffFreq(float newFreq)
{
    centerFrequency = newFreq;
    calculateCoefficients();
}
