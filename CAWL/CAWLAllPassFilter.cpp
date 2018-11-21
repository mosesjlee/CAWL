//
//  CAWLAllPassFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 11/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLAllPassFilter.hpp"

/*
 Default constructor. Set a default center frequency
 */
CAWLAllPassFilter::CAWLAllPassFilter()
{
    cCenterFrequency = 0;
    c0 = 1.0;
    d0 = 0.0;
}

/*
 Default destructor.
 */
CAWLAllPassFilter::~CAWLAllPassFilter()
{
}

double CAWLAllPassFilter::processNextSample(double inputSample)
{
    double xCurrSample;
    double yCurrOutput;
    xCurrSample = inputSample;
    x_a_0 = xCurrSample * a0;
    yCurrOutput = (x_a_0 + cDelayedSample1);
    x_a_1 = xCurrSample * a1;
    x_a_2 = xCurrSample * a2;
    x_b_1 = yCurrOutput * (b1 * -1);
    x_b_2 = yCurrOutput * (b2 * -1);
    
    cDelayedSample1 = x_a_1 + cDelayedSample2 + x_b_1;
    cDelayedSample2 = x_a_2 + x_b_2;
    
    return yCurrOutput * c0 + xCurrSample * d0;
    
//    double outputSample = 0.0;
//    x_a_0 = inputSample * a0;
//    outputSample = (x_a_0 + cDelayedSample1);
//    x_a_1 = inputSample * a1;
//    x_a_2 = inputSample * a2;
//    x_b_1 = inputSample * -b1;
//    x_b_2 = inputSample * -b2;
//
//    cDelayedSample1 = x_a_1 + cDelayedSample2 + x_b_1;
//    cDelayedSample2 = x_a_2 + x_b_2;
//    return outputSample;
}

/*
 Calculate the coeffiencts. Based on the calculations found in
 Udo Zolzer's DAFX book. page 49
 */
void CAWLAllPassFilter::calculateCoefficients()
{
//    double K = tan(M_PI * cCenterFrequency/cSampleRate);
//    double theta_c = 2 * M_PI * cCenterFrequency/cSampleRate;
    double alpha = (tan(M_PI*cCenterFrequency/cSampleRate)-1)/(tan(M_PI*cCenterFrequency/cSampleRate)+1);
    a0 = alpha;
    a1 = 1.0;
    a2 = 0.0;
    b1 = alpha;
    b2 = 0.0;
}
