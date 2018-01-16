//
//  CAWLFuzz.cpp
//  CAWL
//
//  Created by Moses Lee on 10/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLFuzz.hpp"
#define MAX_TONE_GAIN 12.0
#define MIN_TONE_GAIN -12.0
#define MAX_FUZZ_GAIN 10.0

/*
 Default constructor
 */
CAWLFuzz::CAWLFuzz()
{
	cToneControl.setGain(0);
	cToneControl.setCenterFreq(12000);
	cGain = 10;
    cMixLevel = 0.5;
}

/*
 Default destructor
 */
CAWLFuzz::~CAWLFuzz()
{
}

/*
Main processing block. Algorithm based on Udo Zölzer's book DAFX page 127
@param audioStreambuf the buffer of audio stream in 32 bit float
@param numSamples the number of samples in the buffer block
 */
void CAWLFuzz::processBuffer(float * AudioStreamBuf, const unsigned int numSamples)
{
	double xCurrSample = 0.0;
	double absValue = 0.0;
	double yCurrOutput = 0.0;
	double denominator = 0.0;
    for(int i = 0; i < numSamples; i++)
    {
		xCurrSample = AudioStreamBuf[i];
		absValue = abs(xCurrSample);
		if(xCurrSample == 0.0)
		{
			yCurrOutput = xCurrSample;
		}
		else
		{
			denominator = absValue * (1 - exp((cGain * xCurrSample * xCurrSample)/absValue));
			yCurrOutput = xCurrSample/denominator;
		}
        if(yCurrOutput > 1.0)
            yCurrOutput = 1.0;
        if(yCurrOutput < -1.0)
            yCurrOutput = -1.0;
		AudioStreamBuf[i] = yCurrOutput * cMixLevel + xCurrSample * (1 - cMixLevel);
    }
	
	cToneControl.processBuffer(AudioStreamBuf, numSamples);
}

/*
 Adjusts the tone control of the high shelf filter for the fuzz
 @param newToneLevel -> the gain level of the tone control
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
 Sets the gain for the fuzz
 @param newGain -> sets the gain for the fuzz
 */
void CAWLFuzz::setGain(double newGainLevel)
{
    if(newGainLevel > MAX_FUZZ_GAIN)
        cGain = newGainLevel;
    else if (newGainLevel < 1)
        cGain = 1;
    else
        cGain = newGainLevel;
}

/*
 Sets the mix level for the fuzz
 @param newMix -> the new mix level
 */
void CAWLFuzz::setMixLevel(double newMix)
{
    if(newMix > 1.0)
        cMixLevel = 1.0;
    else if (newMix < 0)
        cMixLevel = 0.0;
    else
        cMixLevel = newMix;
}

