//
//  main.cpp
//  cawlTester
//
//  Created by Moses Lee on 11/22/16.
//  Copyright © 2016 Moses Lee. All rights reserved.
//

#include <iostream>
#include "CAWL.hpp"

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	
	
	CAWL * instance = CAWL::Instance();
    float buffer[512], buffer2[512] , buffer3[512], buffer4[512];
    float * ptrToBuf1 = buffer, * ptrToBuf2 = buffer2, * ptrToBuf3 = buffer3, * ptrToBuf4 = buffer4;
	int frameCount = 0, frameCount2 = 0, * fc, * fc2;
	fc = &frameCount; fc2 = &frameCount2;
	double cycleLength = 44100. / 440;
	
	cawlBuffers inputChannel1 = (^(float * data,
								   const unsigned int numSamples){
		double j = *fc;
		for(int i = 0; i < numSamples; i++)
		{
			ptrToBuf1[i] = data[i];
			
            data[i] = data[i];// + (float) sin (2 * M_PI * (j / cycleLength));
			
			j += 1.0;
			if (j > cycleLength)
				j -= cycleLength;
			
		}
		*fc = j;
	});
	
	cawlBuffers inputChannel2 = (^(float * data,
								   const unsigned int numSamples){
		double j = *fc2;
		for(int i = 0; i < numSamples; i++)
		{
			ptrToBuf2[i] = data[i];
            data[i] = data[i];// + (float) sin (2 * M_PI * (j / cycleLength));
			
			j += 1.0;
			if (j > cycleLength)
				j -= cycleLength;
			
			//printf("data %f\n", data[i]);
		}
		
		*fc2 = j;
		//printf("%f ",j);
	});
    
    cawlBuffers inputChannel3 = (^(float * data,
                                   const unsigned int numSamples){
        double j = *fc2;
        for(int i = 0; i < numSamples; i++)
        {
            ptrToBuf3[i] = data[i];
            data[i] = data[i];// + (float) sin (2 * M_PI * (j / cycleLength));
            
            j += 1.0;
            if (j > cycleLength)
                j -= cycleLength;
            
            //printf("data %f\n", data[i]);
        }
        
        *fc2 = j;
        //printf("%f ",j);
    });
	
    cawlBuffers inputChannel4 = (^(float * data,
                                   const unsigned int numSamples){
        double j = *fc2;
        for(int i = 0; i < numSamples; i++)
        {
            ptrToBuf4[i] = data[i];
            data[i] = data[i];// + (float) sin (2 * M_PI * (j / cycleLength));
            
            j += 1.0;
            if (j > cycleLength)
                j -= cycleLength;
            
            //printf("data %f\n", data[i]);
        }
        
        *fc2 = j;
        //printf("%f ",j);
    });
	
	instance->registerInputBlockAtInputChannel(inputChannel1, 0);
	instance->registerInputBlockAtInputChannel(inputChannel2, 1);
    instance->registerInputBlockAtInputChannel(inputChannel3, 2);
    instance->registerInputBlockAtInputChannel(inputChannel4, 3);



	printf("recording shiz\n");
	char c = '0';
	while(c != 'q'){
		c = getchar();
		if(c == 'g')
			instance->startPlaying();
		
		if(c == 's')
			instance->stopPlaying();
	}
    return 0;
}
