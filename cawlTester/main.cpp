//
//  main.cpp
//  cawlTester
//
//  Created by Moses Lee on 11/22/16.
//  Copyright © 2016 Moses Lee. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "CAWL.hpp"
#include "CAWLAmpSimulator.hpp"
#include "CAWLValveTubeSimulator.hpp"
#include "CAWLFIRCombFilter.hpp"
#include "CAWLIIRCombFilter.hpp"
#define SCALE 0.3

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	
	
	CAWL * instance = CAWL::Instance();
    float buffer[512], buffer2[512] , buffer3[512], buffer4[512];
    float * ptrToBuf1 = buffer, * ptrToBuf2 = buffer2, * ptrToBuf3 = buffer3, * ptrToBuf4 = buffer4;
	double frameCount = 0, frameCount2 = 0, * fc, * fc2;
	fc = &frameCount; fc2 = &frameCount2;
    double frameCount3 = 0, frameCount4 = 0, * fc3, * fc4;
    fc3 = &frameCount3; fc4 = &frameCount4;
	double cycleLength = 44100. / 440;
    double cycleLength2 = 44100. / 544.37;
    double * ptr2 = &cycleLength2;
    double cycleLength3 = 44100. / 659.25;
    
    float debugBuffer[8192];
    float *debugPtr = debugBuffer;
    int debugBufWriteCount = 0;
    int * debugCountPtr = &debugBufWriteCount;
	
    
    CAWLAmpSimulator ampSim(2), ampSim2(1), ampSim3(2);
    CAWLAmpSimulator * ptrToAmp = &ampSim, *ptrToAmp2 = &ampSim2, *ptrToAmp3 = &ampSim3;
	CAWLValveTubeSimulator valveSim, valveSim2, valveSim3;
	CAWLValveTubeSimulator * ptrToValve = &valveSim, * ptrToValve2 = &valveSim2, *ptrToValve3 = &valveSim3;
    CAWLFIRCombFilter fir;
    CAWLFIRCombFilter *ptrToFir = &fir;
    CAWLIIRCombFilter iir;
    CAWLIIRCombFilter *ptrToiir = &iir;
    
	cawlBuffers inputChannel1 = (^(float * data,
								   const unsigned int numSamples){
//        double j = *fc;
//            for(int i = 0; i < 441; i++)
//            {
//                //ptrToBuf1[i] = data[i];
//                if(j < 100 ) {
//                data[i] = (float) sin (2 * M_PI * (j / cycleLength));
//                
//                j += 1.0;
//                if (j > cycleLength)
//                    j -= cycleLength;
//                }
//                else {
//                    data[i] = 0.0;
//                }
//            }
//        
//        
//        *fc = j;
        //ptrToFir->processBuffer(data, numSamples);
        ptrToiir->processBuffer(data, numSamples);
		ptrToAmp->processBuffer(data, numSamples);
		//ptrToValve->processBuffer(data,numSamples);
#ifdef WRITE_TO_FILE
        if(*debugCountPtr < 16) {
            memcpy(debugPtr + (*debugCountPtr) * numSamples, data, (512 *sizeof(float)));
            (*debugCountPtr)++;
        }
#endif
        
	});
	
	cawlBuffers inputChannel2 = (^(float * data,
								   const unsigned int numSamples){
//        double j = *fc2;
//        for(int i = 0; i < numSamples; i++)
//        {
//            //ptrToBuf2[i] = data[i];
//            //data[i] = (data[i] + (float) sin (2 * M_PI * (j / cycleLength))) * SCALE * .2;
//
//            j += 1.0;
//            if (j > cycleLength)
//                j -= cycleLength;
//
//            //printf("data %f\n", data[i]);
//        }
        ptrToAmp2->processBuffer(data, numSamples);
        //ptrToValve2->processBuffer(data, numSamples);
//		*fc2 = j;
		//printf("%f ",j);
	});
    
    cawlBuffers inputChannel3 = (^(float * data,
                                   const unsigned int numSamples){
//        double j = *fc3;
//        for(int i = 0; i < numSamples; i++)
//        {
//            //ptrToBuf3[i] = data[i];
//            data[i] = (data[i] + (float) sin (2 * M_PI * (j / *ptr2))) * SCALE * .4;
//
//            j += 1.0;
//            if (j > *ptr2)
//                j -= *ptr2;
//
//            //printf("data %f\n", data[i]);
//        }
//
//        *fc3 = j;
        ptrToAmp3->processBuffer(data, numSamples);
        //ptrToValve3->processBuffer(data, numSamples);
        //printf("%f ",j);
    });
	
    cawlBuffers inputChannel4 = (^(float * data,
                                   const unsigned int numSamples){
        double j = *fc4;
        for(int i = 0; i < numSamples; i++)
        {
            //ptrToBuf4[i] = data[i];
            data[i] = (data[i] + (float) sin (2 * M_PI * (j / cycleLength3))) * SCALE * .3;
            
            j += 1.0;
            if (j > cycleLength3)
                j -= cycleLength3;
            
            //printf("data %f\n", data[i]);
        }
        
        *fc4 = j;
        //printf("%f ",j);
    });
	
	instance->registerInputBlockAtInputChannel(inputChannel1, 0);
	//instance->registerInputBlockAtInputChannel(inputChannel2, 1);
    //instance->registerInputBlockAtInputChannel(inputChannel3, 2);
    //instance->registerInputBlockAtInputChannel(inputChannel4, 3);



	printf("recording shiz\n");
	char c = '0';
	while(c != 'q'){
		c = getchar();
		if(c == 'g')
			instance->startPlaying();
		
		if(c == 's')
			instance->stopPlaying();
        if(c == 'i')
            *ptr2 = 523.25;
        if(c == 'a')
            *ptr2 = 544.37;
        
        if(c == '+'){
			//ampSim.setPreampGain(0.3);;
            iir.setDelay(346);
            //std::cout << "new gain level " << ampSim.getGain() << std::endl;
        }
        if(c == '-'){
            iir.setDelay(400);
            //ampSim.setPreampGain(0.1);
            //std::cout << "new gain level " << ampSim.getGain() << std::endl;
        }
	}
#ifdef WRITE_TO_FILE
    std::ofstream out;
    out.open("/Users/moseslee/Desktop/delayfloat", std::ios::out | std::ios::binary);
    out.write(reinterpret_cast <const char*> (debugBuffer) , 8192 * sizeof(float));
    out.close();
#endif
    return 0;
}
