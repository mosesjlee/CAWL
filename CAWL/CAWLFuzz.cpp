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

/**/
CAWLFuzz::CAWLFuzz()
{
	cToneControl.setGain(0);
	cToneControl.setCenterFreq(12000);
	cGain = 11;
}

/**/
CAWLFuzz::~CAWLFuzz()
{
}

/*
 */
void CAWLFuzz::processBuffer(float * AudioStreamBuf, const unsigned int numSamples)
{
	double xCurrSample = 0.0;
	double absValue = 0.0;
	double yCurrOutput = 0.0;
	
    for(int i = 0; i < numSamples; i++)
    {
		xCurrSample = AudioStreamBuf[i];
		absValue = abs(xCurrSample);
		yCurrOutput = xCurrSample/absValue * (1 - exp((cGain * xCurrSample * xCurrSample)/absValue));
		AudioStreamBuf[i] = yCurrOutput;
    }
	
	//toneControl.processBuffer(buf, numSamples);
}

/*
 */
void CAWLFuzz::adjustFuzzTone(double newToneLevel)
{
	if(newToneLevel > MAX_TONE_GAIN)
		cToneControl.setGain(MAX_TONE_GAIN);
	else if (newToneLevel < MIN_TONE_GAIN)
		cToneControl.setGain(MIN_TONE_GAIN);
	else
		cToneControl.setGain(newToneLevel);
}

/*
 */
void CAWLFuzz::setGain(double newGain)
{
	cGain = newGain;
}

/*
 */
void CAWLFuzz::setMix(double newMix)
{
	
}

