//
//  CAWLSineWaveOsc.cpp
//  CAWL
//
//  Created by Moses Lee on 10/23/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLSineWaveOsc.hpp"
#include "CAWLSoundModule.hpp"

CAWLSineWaveOsc::CAWLSineWaveOsc()
{
    sampleRate  = DEFAULT_SR;
    freq        = 440;
    cycleLength = MAX_TABLE_SIZE * freq/sampleRate;
    counter     = 0.0;
    
    //Create the table
    table = new double[(int)MAX_TABLE_SIZE];
    
    //Fill the table with samples
    for(int i = 0; i < MAX_TABLE_SIZE; i++)
    {
        table[i] = sin(2 * M_PI * (double) i/MAX_TABLE_SIZE);
        //(void) printf("%f\n", table[i]);
    }
}

CAWLSineWaveOsc::~CAWLSineWaveOsc()
{
    delete [] table;
}



