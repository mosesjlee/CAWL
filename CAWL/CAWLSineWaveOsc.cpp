//
//  CAWLSineWaveOsc.cpp
//  CAWL
//
//  Created by Moses Lee on 10/23/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLSineWaveOsc.hpp"
#include "CAWLSoundModule.hpp"

/*
 Constructor of the sine wave table oscialltor
 */
CAWLSineWaveOsc::CAWLSineWaveOsc()
{
    cSampleRate  = DEFAULT_SR;
    cFreq        = 440;
    cCycleLength = MAX_TABLE_SIZE * cFreq/cSampleRate;
    cCounter     = 0.0;
    
    //Create the table
    cWaveTable = new double[(int)MAX_TABLE_SIZE];
    
    //Fill the table with samples
    for(int i = 0; i < MAX_TABLE_SIZE; i++)
    {
        cWaveTable[i] = sin(2 * M_PI * (double) i/MAX_TABLE_SIZE);
    }
}

/*
 Destructor
 */
CAWLSineWaveOsc::~CAWLSineWaveOsc()
{
    delete [] cWaveTable;
}



