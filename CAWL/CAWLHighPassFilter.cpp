//
//  CAWLHighPassFilter.cpp
//  SimpleOsc
//
//  Created by Moses Lee on 10/4/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLHighPassFilter.hpp"

CAWLHighPassFilter::CAWLHighPassFilter(float cutOffFreq)
{
    cutOffFrequency = cutOffFreq; //Default;
    delayLine.setDelayTimeInSamples(1.0);
    calculateCoefficients();
}

CAWLHighPassFilter::~CAWLHighPassFilter()
{
}

void CAWLHighPassFilter::calculateCoefficients()
{
    theta_c = 2 * M_PI * cutOffFrequency/sampleRate;
    gamma   = 2 + cos(theta_c);
    b_1     = gamma - sqrt(gamma * gamma - 1);
    a_0     = 1 - b_1;
    
    //Update the IIR Filter specs
    setMixLevel(a_0);
    CAWLHighPassFilter::setFeedbackGain(-b_1);
}

void CAWLHighPassFilter::changeCutOffFreq(float newFreq)
{
    cutOffFrequency = newFreq;
    calculateCoefficients();
}

void CAWLHighPassFilter::setFeedbackGain(float newGain)
{
    mFeedbackGain = newGain;
}


