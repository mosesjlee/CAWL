//
//  CAWLFuzz.cpp
//  CAWL
//
//  Created by Moses Lee on 10/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLFuzz.hpp"
#define MAX_TONE_GAIN 12.0
#define MIN_TONE_GAIN 12.0

CAWLFuzz::CAWLFuzz()
{
	toneControl.setGain(0);
	toneControl.setCutOffFreq(12000);
	mGain = 11;
}

CAWLFuzz::~CAWLFuzz()
{
    
}

void CAWLFuzz::processBuffer(float * buf, const unsigned int numSamples)
{
	double xCurrSample = 0.0;
	double absValue = 0.0;
	double yCurrOutput = 0.0;
	
    for(int i = 0; i < numSamples; i++)
    {
		xCurrSample = buf[i];
		absValue = abs(xCurrSample);
		yCurrOutput = xCurrSample/absValue * (1 - exp((mGain * xCurrSample * xCurrSample)/absValue));
		buf[i] = yCurrOutput;
    }
	
	//toneControl.processBuffer(buf, numSamples);
}

void CAWLFuzz::adjustFuzzTone(double newToneLevel)
{
	if(newToneLevel > MAX_TONE_GAIN)
		toneControl.setGain(MAX_TONE_GAIN);
	else if (newToneLevel < MIN_TONE_GAIN)
		toneControl.setGain(MIN_TONE_GAIN);
	else
		toneControl.setGain(newToneLevel);
}

void CAWLFuzz::setGain(double newGain)
{
	mGain = newGain;
}

void CAWLFuzz::setMix(double newMix)
{
	
}

