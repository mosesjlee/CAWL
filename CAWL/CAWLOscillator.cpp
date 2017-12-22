//
//  CAWLOscillator.cpp
//  CAWL
//
//  Created by Moses Lee on 10/23/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLOscillator.hpp"
#include <stdio.h>

/*
 Returns the next sample in the table
 @return the next sample in the table
 */
double CAWLOscillator::getNextSample()
{
    double retval = cWaveTable[(int) cCounter];
    
    //Increment by cycleLength
    cCounter += cCycleLength;
    
    //Out of bounds
    if(cCounter >= MAX_TABLE_SIZE) cCounter -= MAX_TABLE_SIZE;
    if(cCounter < 0) cCounter += MAX_TABLE_SIZE;
    
    //Return the Next sample from the table
    return retval;
}
/*
 Sets the wave table oscillator frequency
 @param newFreq -> the new frequency of the wave table
 */
void CAWLOscillator::setWaveTableFreq(double newFreq)
{
    cFreq = newFreq;
    cCycleLength = MAX_TABLE_SIZE * cFreq/cSampleRate;
}

/*
 Sets the sample rate of the table. Default is 44100
 @param  newSampleRate -> the new sample rate of the table
 */
void CAWLOscillator::setSampleRate(double newSampleRate)
{
    cSampleRate = newSampleRate;
}

