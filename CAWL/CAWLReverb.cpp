//
//  CAWLReverb.cpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLReverb.hpp"
unsigned debug_int = 0;

/*
 Default constructor
 */
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
    
    cLpfGain[0] = 0.1482;
    cLpfGain[1] = 0.1399;
    cLpfGain[2] = 0.1350;
    cLpfGain[3] = 0.1316;
    cLpfGain[4] = 0.1233;
    cLpfGain[5] = 0.1735;
    
    cCombGain[0] = 0.46;
    cCombGain[1] = 0.48;
    cCombGain[2] = 0.50;
    cCombGain[3] = 0.52;
    cCombGain[4] = 0.53;
    cCombGain[5] = 0.55;
    
    cApDelayLine.setDelayTimeInMilliseconds(6);
    cApGain = 0.4;
    cApOut = 0.0;
    
    cReverbMix = 1.0;
}

/*
 Default destructor
 */
CAWLReverb::~CAWLReverb()
{
    delete [] cCombDelayLineArray;
}

/*
 Main processing block. The Moorer's implementation is based off the
 diagram in Will Pirkle's Designing Audio Effect Plugins in C++
 pg. 376
 @param audioStreambuf the buffer of audio stream in 32 bit float
 @param numSamples the number of samples in the buffer block
 */
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
        audioStreamBuf[i] = yOutputSample * cReverbMix + (1 - cReverbMix) * xCurrSample;
    }
}

/*
 Set reverb time
 @param newTime -> the new reverb time
 */
void CAWLReverb::setReverbTime(double newTime)
{
    
}

/*
 Set reverb mix
 @param newMix -> the new mix level
 */
void CAWLReverb::setReverbMix(double newMix)
{
    if (newMix > 1.0)
        cReverbMix = 1.0;
    else if(newMix < 0.0)
        cReverbMix = 0.0;
    else
        cReverbMix = newMix;
}

/*
 Set reverb tone
 @param newToneLevel -> the new tone level
 */
void CAWLReverb::adjustReverbTone(double newToneLevel)
{
    cToneControl.setGain(newToneLevel);
}




