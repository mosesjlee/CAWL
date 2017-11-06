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
	
	//From will pirkle's book
    //rising edge
    double mt1 = 4.0/MAX_TABLE_SIZE;
    double bt1 = 0.0;
    
    //rising edge 2
    double mt2 = 4.0/MAX_TABLE_SIZE;
    double bt2 = -1.0;
    
    //falling edge
    double mtf2 = -4.0/MAX_TABLE_SIZE;
    double btf2 = +1.0;
	
    //Fill the table with samples
    for(int i = 0; i < MAX_TABLE_SIZE; i++)
    {
        if(i < 4096)
            table[i] = mt1 * i + bt1;
        else if (i >= 4096 && i <12288)
			table[i] = mtf2 * (i-4096) + btf2;
        else
            table[i] = mt2 * (i-12288) + bt2;
        printf("Triangle table[%d] == %f\n", i, table[i]);
    }
}

CAWLTriangleWaveOsc::~CAWLTriangleWaveOsc()
{
    delete [] table;
}
