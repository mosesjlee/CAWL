//
//  CAWLWahWah.cpp
//  CAWL
//
//  Created by Moses Lee on 10/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLWahWah.hpp"

CAWLWahWah::CAWLWahWah()
{
    bandPass = new CAWLBandPassFilter();
    triangeWave = new CAWLTriangleWaveOsc();
}

CAWLWahWah::~CAWLWahWah()
{
    delete bandPass;
    delete triangeWave;
}

void CAWLWahWah::processBuffer(float * buf, const unsigned int numSamples)
{
    for(int i = 0; i < numSamples; i++)
    {
        
    }
}







