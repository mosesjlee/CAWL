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

/**/
CAWLOverdrive::CAWLOverdrive()
{
	cToneControl.setGain(0);
	cToneControl.setCenterFreq(12000);
}

/**/
CAWLOverdrive::~CAWLOverdrive()
{
    
}

//From Udo Zölzer's book DAFX page 125
/**/
void CAWLOverdrive::processBuffer(float * buf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double absSample = 0.0;
    double yCurrOutput = 0.0;
    double th = 1.0/3.0;
    for(int i = 0; i < numSamples; i++)
    {
		xCurrSample = buf[i];
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
        
        buf[i] = yCurrOutput;
    }
	
	cToneControl.processBuffer(buf, numSamples);
}

/**/
void CAWLOverdrive::adjustOverdriveTone(double newToneLevel)
{
	if(newToneLevel > MAX_TONE_GAIN)
		cToneControl.setGain(MAX_TONE_GAIN);
	else if (newToneLevel < MIN_TONE_GAIN)
		cToneControl.setGain(MIN_TONE_GAIN);
	else
		cToneControl.setGain(newToneLevel);
}

