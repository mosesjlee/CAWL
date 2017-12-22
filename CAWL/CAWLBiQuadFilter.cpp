//
//  CAWLBiQuadFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 10/4/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLBiQuadFilter.hpp"

/*
 Default constructor
 */
CAWLBiQuadFilter::CAWLBiQuadFilter()
{
}

/*
 Default destructor
 */
CAWLBiQuadFilter::~CAWLBiQuadFilter()
{
	
}

/*
 Main processing block
 @param audioStreambuf the buffer of audio stream in 32 bit float
 @param numSamples the number of samples in the buffer block
 */
void CAWLBiQuadFilter::processBuffer(float * audioStreamBuf, const unsigned int numSamples)
{
	float xCurrSample = 0.0;
	float yCurrOutput = 0.0;

	
	for(unsigned int i = 0; i < numSamples; i++)
	{
        xCurrSample = audioStreamBuf[i];
        x_a_0 = xCurrSample * a0;
        yCurrOutput = (x_a_0 + cDelayedSample1);
        x_a_1 = xCurrSample * a1;
        x_a_2 = xCurrSample * a2;
        x_b_1 = yCurrOutput * (b1 * -1);
        x_b_2 = yCurrOutput * (b2 * -1);

		cDelayedSample1 = x_a_1 + cDelayedSample2 + x_b_1;
		cDelayedSample2 = x_a_2 + x_b_2;

        audioStreamBuf[i] = yCurrOutput * c0 + xCurrSample * d0;
	}
}

/*
 Sets the gain for the filter
 @param newGain -> the new gain for the filter
 */
void CAWLBiQuadFilter::setGain(double newGain)
{
    if(newGain > 24.0)
        newGain = 24.0;
    else if(newGain < -24.0)
        newGain = -24.0;
    else
        cGain = newGain;
    calculateCoefficients();
}

/*
 Sets the center frequency for the filter
 @param newFreq -> new frequency of the filter
 */
void CAWLBiQuadFilter::setCenterFreq(double newFreq)
{
    cCenterFrequency = newFreq;
    calculateCoefficients();
}
