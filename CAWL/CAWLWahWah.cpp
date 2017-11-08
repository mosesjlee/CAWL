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
    //bandPass = new CAWLBandPassFilter();
    filter = new CAWLBandPassFilter();
    triangeWave = new CAWLTriangleWaveOsc();
    triangeWave->setFreq(1);
    filter->setCutOffFreq(3000);
}

CAWLWahWah::~CAWLWahWah()
{
    //delete bandPass;
    delete triangeWave;
    delete filter;
}

//void CAWLWahWah::processBuffer(float * buf, const unsigned int numSamples)
//{
//    for(int i = 0; i < numSamples; i++)
//    {
//        
//    }
//}







