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
    combDelayLineArray = new CAWLDelayLine[NUM_MOORERS_DELAYLINE];
    combDelayLineArray[0].setDelayTimeInMilliseconds(50);
    combDelayLineArray[1].setDelayTimeInMilliseconds(56);
    combDelayLineArray[2].setDelayTimeInMilliseconds(61);
    combDelayLineArray[3].setDelayTimeInMilliseconds(68);
    combDelayLineArray[4].setDelayTimeInMilliseconds(72);
    combDelayLineArray[5].setDelayTimeInMilliseconds(78);
    
    combFilter[0].setDelay(50);
    combFilter[1].setDelay(56);
    combFilter[2].setDelay(61);
    combFilter[3].setDelay(68);
    combFilter[4].setDelay(72);
    combFilter[5].setDelay(78);
    
    
    for(int i = 0; i < NUM_MOORERS_DELAYLINE; i++) 
        delayLineZ_1[i] = delayLineOut[i] = lpfZ_1Samples[i] = 0.0;
    
    lpfGain[0] = 0.4482;
    lpfGain[1] = 0.4399;
    lpfGain[2] = 0.4350;
    lpfGain[3] = 0.4316;
    lpfGain[4] = 0.4233;
    lpfGain[5] = 0.3735;
    
    combGain[0] = 0.46;
    combGain[1] = 0.47;
    combGain[2] = 0.475;
    combGain[3] = 0.48;
    combGain[4] = 0.49;
    combGain[5] = 0.50;
    
    apDelayLine.setDelayTimeInMilliseconds(6);
    apGain = 0.7;
    apOut = 0.0;
}

CAWLReverb::~CAWLReverb()
{
    
}

void CAWLReverb::processBuffer(float * buf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double yOutputSample = 0.0;
    double lastApout = apOut;
    for(unsigned i = 0; i < numSamples; i++)
    {
        if(debug_int ==2200)
            printf("BREAL\n");
        xCurrSample = buf[i];
        for(int j = 0; j < NUM_MOORERS_DELAYLINE; j++)
        {
            delayLineOut[j] = combDelayLineArray[j].processNextSample(xCurrSample + combGain[j] * lpfZ_1Samples[j]);
            lpfZ_1Samples[j] = delayLineOut[j] + lpfZ_1Samples[j] * lpfGain[j];
            delayLineZ_1[j] = delayLineOut[j];
        }
        
        double summation = 0.0;
        for (int k = 0; k < NUM_MOORERS_DELAYLINE; k++)
            summation += delayLineOut[0];

        apOut = apDelayLine.processNextSample(summation + apOut * apGain);
        yOutputSample = (summation * -apGain + apOut);
        buf[i] = yOutputSample;
        debug_int++;
        
    }
}

void CAWLReverb::setReverbTime(double newTime)
{
    
}

void CAWLReverb::setReverbMix(double newMix)
{
    
}






