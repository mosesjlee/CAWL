//
//  CAWLAllPassFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 11/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLAllPassFilter.hpp"

CAWLAllPassFilter::CAWLAllPassFilter()
{
    cCenterFrequency = 0;
}

CAWLAllPassFilter::~CAWLAllPassFilter()
{
    
}

void CAWLAllPassFilter::processBuffer(float * buf, const unsigned int numSamples)
{
    
}

double CAWLAllPassFilter::processNextSample(double inputSample)
{
    double outputSample = 0.0;
    x_a_0 = inputSample * a0;
    outputSample = (x_a_0 + cDelayedSample1);
    x_a_1 = inputSample * a1;
    x_a_2 = inputSample * a2;
    x_b_1 = inputSample * -b1;
    x_b_2 = inputSample * -b2;

    cDelayedSample1 = x_a_1 + cDelayedSample2 + x_b_1;
    cDelayedSample2 = x_a_2 + x_b_2;
    return outputSample;
}

void CAWLAllPassFilter::calculateCoefficients()
{
    double K = tan(M_PI * cCenterFrequency/cSampleRate);
    double Q = 2;
    a0 = ((K * K * Q) - K+Q)/((K * K * Q) + K + Q);
    a1 = (2 * Q * (K * K - 1.0))/((K * K * Q) + K + Q);
    a2 = 1.0;
    b1 = a1;
    b2 = a0;
}
