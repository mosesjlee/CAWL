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
	c0 = 1.0;
	d0 = 0.0;
}

CAWLAllPassFilter::~CAWLAllPassFilter()
{
    
}

double CAWLAllPassFilter::processNextSample(double inputSample)
{
	double xCurrSample = inputSample;
	x_a_0 = xCurrSample * a0;
	double yCurrOutput = (x_a_0 + cDelayedSample1);
	x_a_1 = xCurrSample * a1;
	x_a_2 = xCurrSample * a2;
	x_b_1 = yCurrOutput * (b1 * -1);
	x_b_2 = yCurrOutput * (b2 * -1);
	
	cDelayedSample1 = x_a_1 + cDelayedSample2 + x_b_1;
	cDelayedSample2 = x_a_2 + x_b_2;
	
	return yCurrOutput * c0 + xCurrSample * d0;
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
