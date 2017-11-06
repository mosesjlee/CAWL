//
//  CAWLTimeVariableFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 11/6/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLTimeVariableFilter.hpp"

void CAWLTimeVariableFilter::setTimeRate(double newRate)
{
	triangeWave->setFreq(newRate);
}

void CAWLTimeVariableFilter::setMixLevel(double newMixLevel)
{
	mixLevel = newMixLevel;
}

void CAWLTimeVariableFilter::processBuffer(float * buf, const unsigned int numSamples)
{
	for(int i = 0; i < numSamples; i++)
	{
		
	}
}
