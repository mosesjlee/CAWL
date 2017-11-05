//
//  CAWLOscillator.cpp
//  CAWL
//
//  Created by Moses Lee on 10/23/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLOscillator.hpp"
#include <stdio.h>
double CAWLOscillator::getNextSample()
{
    double retval = table[(int) counter];
    
    //Increment by cycleLength
    counter += cycleLength;
    
    //Out of bounds
    if(counter >= MAX_TABLE_SIZE) counter -= MAX_TABLE_SIZE;
    if(counter < 0) counter += MAX_TABLE_SIZE;
    
    return retval;
}

void CAWLOscillator::setFreq(double newFreq)
{
    freq = newFreq;
    cycleLength = MAX_TABLE_SIZE * freq/sampleRate;
    printf("set new freq of %f\n", newFreq);
}

void CAWLOscillator::setSampleRate(double newSampleRate)
{
    sampleRate = newSampleRate;
}

