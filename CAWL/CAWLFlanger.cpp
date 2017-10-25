//
//  CAWLFlanger.cpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLFlanger.hpp"

CAWLFlanger::CAWLFlanger()
{
    sine = new CAWLSineWaveOsc();
    modSpeed = 1.0;
    modDepth = 6.0;
    mMixLevel = .5;
    mFeedbackGain = .5;
    mFeedForwardGain = .5;
    sine->setFreq(modSpeed);
}


CAWLFlanger::~CAWLFlanger()
{
    delete sine;
}

void CAWLFlanger::processBuffer(float * buf, const unsigned int numSamples)
{
	double xCurrSample = 0.0;
	double zSample = 0.0;
	double yCurrOutput = lastSampleOfBlock;
	for(int i = 0; i < numSamples; i++)
	{
		xCurrSample = buf[i] * mMixLevel;
        yCurrOutput = buf[i] + mFeedbackGain * zSample;
        zSample = delayLine.processNextSample(yCurrOutput);

		buf[i] = xCurrSample + yCurrOutput * mFeedForwardGain;

		delayLine.setDelayTimeInMilliseconds(flangedValue());
	}
	lastSampleOfBlock = yCurrOutput;
}

double CAWLFlanger::flangedValue()
{
	return modDepth * fabs(sine->getNextSample());
}

void CAWLFlanger::setModulationDepth(double newModDepth)
{
    modDepth = newModDepth;
}

void CAWLFlanger::setMixLevel(double mixLevel)
{
	mMixLevel = mixLevel;
}

void CAWLFlanger::setModulationSpeed(double newModSpeed)
{
    modSpeed = newModSpeed;
	sine->setFreq(modSpeed);
}






