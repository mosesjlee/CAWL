//
//  CAWLLowPassFilter.cpp
//  CAWLLowPassFilter
//
//  Created by Moses Lee on 10/4/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLLowPassFilter.hpp"
CAWLLowPassFilter::CAWLLowPassFilter(float cutOffFreq)
{
    cutOffFrequency = cutOffFreq; //Default;
    calculateCoefficients();
    delayLine.setDelayTimeInSamples(1.0);
}

CAWLLowPassFilter::~CAWLLowPassFilter()
{
}

void CAWLLowPassFilter::calculateCoefficients()
{
    theta_c = 2 * M_PI * cutOffFrequency/sampleRate;
    gamma   = 2 - cos(theta_c);
    b_1     = sqrt(gamma * gamma - 1) - gamma;
    a_0     = 1 + b_1;
    
    //Update the IIR Filter specs
    setMixLevel(a_0);
    setFeedbackGain(-b_1);
}

void CAWLLowPassFilter::changeCutOffFreq(float newFreq)
{
    cutOffFrequency = newFreq;
    calculateCoefficients();
}


