//
//  CAWLPhaser.cpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLPhaser.hpp"

CAWLPhaser::CAWLPhaser()
{
	triangeWave = new CAWLTriangleWaveOsc();
}

CAWLPhaser::~CAWLPhaser()
{
    
}

void CAWLPhaser::processBuffer(float * buf, const unsigned int numSamples)
{
    
}
