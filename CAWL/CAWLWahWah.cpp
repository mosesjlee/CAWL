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
    triangeWave = new CAWLTriangleWaveOsc();
    triangeWave->setFreq(1);
	centerFrequency = 3000;
	
	freq = float(1.5);
	startphase = 0;
	depth = (float)0.7;
	freqofs = (float)0.3;
	res = float(2.5);
	mCurRate = 44100.0;
	lfoskip = freq * 2 * M_PI / mCurRate;
	phase = 0;
	
    //State Variable
    y_h = 0;
    y_b = 0;
    y_l = 0;
    y_b_n1 = 0;
    y_l_n1 = 0;
    max_y_b = 0.1;
}

CAWLWahWah::~CAWLWahWah()
{
    delete triangeWave;
}

//void CAWLWahWah::processBuffer(float * buf, const unsigned int numSamples)
//{
//    for(int i = 0; i < numSamples; i++)
//    {
//        
//    }
//}







