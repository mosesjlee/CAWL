//
//  CAWLTriangleWaveOsc.cpp
//  CAWL
//
//  Created by Moses Lee on 10/23/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLTriangleWaveOsc.hpp"
#include "CAWLSoundModule.hpp"

CAWLTriangleWaveOsc::CAWLTriangleWaveOsc()
{
    sampleRate  = DEFAULT_SR;
    freq        = 440;
    cycleLength = freq * MAX_TABLE_SIZE/sampleRate;
    counter     = 0.0;
    
    //Create the table
    table = new double[(int)MAX_TABLE_SIZE];
    
    //Fill the table with samples
    for(int i = 0; i < MAX_TABLE_SIZE; i++)
    {
        table[i] = sin(2 * M_PI * i/MAX_TABLE_SIZE);
    }
}

CAWLTriangleWaveOsc::~CAWLTriangleWaveOsc()
{
    delete [] table;
}
