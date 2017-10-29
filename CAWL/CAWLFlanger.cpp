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
    modDepth = 7.0;
    mMixLevel = 0.5;
    mFeedbackGain = 0.5;
    mFeedForwardGain = 1.0;
    sine->setFreq(modSpeed);
	delayLine.setDelayTimeInSamples(0);
}


CAWLFlanger::~CAWLFlanger()
{
    delete sine;
}

void CAWLFlanger::processBuffer(float * buf, const unsigned int numSamples)
{
	double xCurrSample = 0.0;
	double zDelayedSample = 0.0;
	double xHCurrSample = lastSampleOfBlock;
	double yCurrOutput = 0.0;
	for(int i = 0; i < numSamples; i++)
	{
		xCurrSample = buf[i];
		zDelayedSample = delayLine.processNextSample(xHCurrSample);
		xHCurrSample = xCurrSample + zDelayedSample * mFeedbackGain;
		yCurrOutput = zDelayedSample * mFeedForwardGain + xHCurrSample * mMixLevel;
		buf[i] = yCurrOutput + xCurrSample * dryMix;
		buf[i] = xCurrSample + yCurrOutput * mFeedForwardGain;

		delayLine.setDelayTimeInMilliseconds(flangedValue());
	}
	lastSampleOfBlock = xHCurrSample;
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






