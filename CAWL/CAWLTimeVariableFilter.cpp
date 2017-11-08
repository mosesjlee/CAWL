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

//https://searchcode.com/codesearch/view/20121801/ look at that
void CAWLTimeVariableFilter::processBuffer(float * buf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double yCurrSample = 0.0;
    filter->processBuffer(buf, numSamples);
    filter->setCutOffFreq(1000 * triangeWave->getNextSample() + 3000);
}
