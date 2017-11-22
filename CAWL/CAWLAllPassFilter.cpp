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
    centerFrequency = 0;
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
    x_a_0 = inputSample * a_0;
    outputSample = (x_a_0 + delayedSample1);
    x_a_1 = inputSample * a_1;
    x_a_2 = inputSample * a_2;
    x_b_1 = inputSample * (b_1 * -1);
    x_b_2 = inputSample * (b_2 * -1);

    delayedSample1 = x_a_1 + delayedSample2 + x_b_1;
    delayedSample2 = x_a_2 + x_b_2;
    return outputSample;
}

void CAWLAllPassFilter::calculateCoefficients()
{
    double K = tan(M_PI * centerFrequency/sampleRate);
    double Q = .707;
    a_0 = ((K * K * Q) - K+Q)/((K * K * Q) + K + Q);
    a_1 = (2 * Q * (K * K - 1.0))/((K * K * Q) + K + Q);
    a_2 = 1.0;
    b_1 = a_1;
    b_2 = a_0;
}
