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
    
    for(int i = 0; i < NUM_MOORERS_DELAYLINE; i++) 
        delayLineZ_1[i] = delayLineOut[i] = lpfZ_1Samples[i] = 0.0;
    
    lpfGain[0] = 0.1482;
    lpfGain[1] = 0.1399;
    lpfGain[2] = 0.1350;
    lpfGain[3] = 0.1316;
    lpfGain[4] = 0.1233;
    lpfGain[5] = 0.0735;
    
    combGain[0] = 0.14;
    combGain[1] = 0.15;
    combGain[2] = 0.155;
    combGain[3] = 0.16;
    combGain[4] = 0.17;
    combGain[5] = 0.18;
    
    apDelayLine.setDelayTimeInMilliseconds(6);
    apGain = 0.7;
    apOut = 0.0;
}

CAWLReverb::~CAWLReverb()
{
    delete [] combDelayLineArray;
}

void CAWLReverb::processBuffer(float * buf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double yOutputSample = 0.0;
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






