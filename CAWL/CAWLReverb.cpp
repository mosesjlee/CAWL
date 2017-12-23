//
//  CAWLReverb.cpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLReverb.hpp"
unsigned debug_int = 0;
CAWLReverb::CAWLReverb()
{
    cCombDelayLineArray = new CAWLDelayLine[NUM_MOORERS_DELAYLINE];
    cCombDelayLineArray[0].setDelayTimeInMilliseconds(50);
    cCombDelayLineArray[1].setDelayTimeInMilliseconds(56);
    cCombDelayLineArray[2].setDelayTimeInMilliseconds(61);
    cCombDelayLineArray[3].setDelayTimeInMilliseconds(68);
    cCombDelayLineArray[4].setDelayTimeInMilliseconds(72);
    cCombDelayLineArray[5].setDelayTimeInMilliseconds(78);
    
    for(int i = 0; i < NUM_MOORERS_DELAYLINE; i++) 
        cDelayLineZ_1[i] = cDelayLineOut[i] = cLpfZ_1Samples[i] = 0.0;
    
    cLpfGain[0] = 0.4482;
    cLpfGain[1] = 0.4399;
    cLpfGain[2] = 0.4350;
    cLpfGain[3] = 0.4316;
    cLpfGain[4] = 0.4233;
    cLpfGain[5] = 0.3735;
    
    cCombGain[0] = 0.46;
    cCombGain[1] = 0.47;
    cCombGain[2] = 0.475;
    cCombGain[3] = 0.48;
    cCombGain[4] = 0.49;
    cCombGain[5] = 0.50;
    
    cApDelayLine.setDelayTimeInMilliseconds(6);
    cApGain = 0.7;
    cApOut = 0.0;
}

CAWLReverb::~CAWLReverb()
{
    delete [] cCombDelayLineArray;
}

void CAWLReverb::processBuffer(float * audioStreamBuf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double yOutputSample = 0.0;
    for(unsigned i = 0; i < numSamples; i++)
    {
        xCurrSample = audioStreamBuf[i];
        for(int j = 0; j < NUM_MOORERS_DELAYLINE; j++)
        {
            cDelayLineOut[j] = cCombDelayLineArray[j].processNextSample(xCurrSample + cCombGain[j] * cLpfZ_1Samples[j]);
            cLpfZ_1Samples[j] = cDelayLineOut[j] + cLpfZ_1Samples[j] * cLpfGain[j];
            cDelayLineZ_1[j] = cDelayLineOut[j];
        }
        
        double summation = 0.0;
        for (int k = 0; k < NUM_MOORERS_DELAYLINE; k++)
            summation += cDelayLineOut[k];

        cApOut = cApDelayLine.processNextSample(summation + cApOut * cApGain);
        yOutputSample = (summation * -cApGain + cApOut);
        audioStreamBuf[i] = yOutputSample;
    }
}

void CAWLReverb::setReverbTime(double newTime)
{
    
}

void CAWLReverb::setReverbMix(double newMix)
{
    
}






