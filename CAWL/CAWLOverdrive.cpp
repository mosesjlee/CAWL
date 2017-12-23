//
//  CAWLOverdrive.cpp
//  CAWL
//
//  Created by Moses Lee on 10/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLOverdrive.hpp"
#include <math.h>

#define MAX_TONE_GAIN 12.0
#define MIN_TONE_GAIN 12.0
#define MAX_OVERDRIVE_GAIN 10.0

/*
 Default constructor
 */
CAWLOverdrive::CAWLOverdrive()
{
	cToneControl.setGain(0);
	cToneControl.setCenterFreq(10000);
}

/*
 Default destructor
 */
CAWLOverdrive::~CAWLOverdrive()
{
}


/*
 Main processing block. Algorithm based on Udo Zölzer's book DAFX page 125
 @param audioStreambuf the buffer of audio stream in 32 bit float
 @param numSamples the number of samples in the buffer block
 */
void CAWLOverdrive::processBuffer(float * audioStreamBuf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double absSample = 0.0;
    double yCurrOutput = 0.0;
    double th = 1.0/3.0;
    for(int i = 0; i < numSamples; i++)
    {
		xCurrSample = audioStreamBuf[i] * cGain;
        absSample = fabs(xCurrSample);
        if(absSample >= 0.0 && absSample <= th)
        {
            yCurrOutput = 2.0 * xCurrSample;
        }
        else if(absSample >= th && absSample <= (2.0/3.0))
        {
            yCurrOutput = (3.0-(2.0 - 3.0 * xCurrSample) * (2.0 - 3.0 * xCurrSample))/3.0;
        }
        else if(absSample >= (2.0/3.0) && absSample <= 1.0)
        {
            yCurrOutput = xCurrSample < 0.0 ? -1.0 : 1.0;
        }
        
        audioStreamBuf[i] = yCurrOutput;
    }
	
	cToneControl.processBuffer(audioStreamBuf, numSamples);
}

/*
 Adjust the gain of the high shelving filter for tone control
 @param newToneLevel -> the gain for the high shelving filter
 */
void CAWLOverdrive::adjustOverdriveTone(double newToneLevel)
{
	if(newToneLevel > MAX_TONE_GAIN)
		cToneControl.setGain(MAX_TONE_GAIN);
	else if (newToneLevel < MIN_TONE_GAIN)
		cToneControl.setGain(MIN_TONE_GAIN);
	else
		cToneControl.setGain(newToneLevel);
}

/*
 Set the gain of the over drive
 @param newGainLevel -> the gain level of the over drive
 */
void CAWLOverdrive::adjustOverdriveGain(double newGainLevel)
{
    if(newGainLevel > MAX_OVERDRIVE_GAIN)
        cGain = newGainLevel;
    else if (newGainLevel < 1)
        cGain = 1;
    else
        cGain = newGainLevel;
}



