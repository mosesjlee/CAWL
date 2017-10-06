//
//  CAWLBiQuadFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 10/4/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLBiQuadFilter.hpp"

CAWLBiQuadFilter::CAWLBiQuadFilter()
{
	a_0 = a_1 = a_2 = b_1 = b_2 = c_0 = d_0 = 0.0;
	firstOrderDelayLine.setDelayTimeInSamples(1.0);
	secondOrderDelayLine.setDelayTimeInSamples(1.0);
}

CAWLBiQuadFilter::~CAWLBiQuadFilter()
{
	
}

void CAWLBiQuadFilter::processBuffer(float * buf, const unsigned int numSamples)
{
	float xCurrSample = 0.0;
	float yCurrOutput = 0.0;

	float delayedSample1 = 0.0, delayedSample2 = 0.0;
	for(unsigned int i = 0; i < numSamples; i++)
	{
		xCurrSample = buf[i];
		x_a_0 = xCurrSample * a_0;
		x_a_1 = xCurrSample * a_1;
		x_a_2 = xCurrSample * a_2;
		delayedSample1 = firstOrderDelayLine.processNextSample(x_a_2 + x_b_2);
		delayedSample2 = secondOrderDelayLine.processNextSample(x_a_1 + delayedSample1 + x_b_1);
		yCurrOutput = (x_a_0 + delayedSample2) * c_0 + xCurrSample * d_0;
		x_b_1 = yCurrOutput * b_1;
		x_b_2 = yCurrOutput * b_2;
        buf[i] = yCurrOutput;
	}
}
