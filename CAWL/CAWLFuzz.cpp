//
//  CAWLFuzz.cpp
//  CAWL
//
//  Created by Moses Lee on 10/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLFuzz.hpp"

CAWLFuzz::CAWLFuzz()
{
	toneControl.setGain(0);
	toneControl.setCutOffFreq(12000);
}

CAWLFuzz::~CAWLFuzz()
{
    
}

void CAWLFuzz::processBuffer(float * buf, const unsigned int numSamples)
{
    for(int i = 0; i < numSamples; i++)
    {
        
    }
}

void CAWLFuzz::adjustFuzzTone(double newToneLevel)
{
	
}
