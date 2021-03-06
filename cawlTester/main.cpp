//
//  main.cpp
//  cawlTester
//
//  Created by Moses Lee on 11/22/16.
//  Copyright © 2016 Moses Lee. All rights reserved.
//


#include "CAWL.hpp"
#include "CAWLValveTubeSimulator.hpp"
#include "CAWLFIRCombFilter.hpp"
#include "CAWLIIRCombFilter.hpp"
#include "CAWLUniversalCombFilter.hpp"
#include "CAWLLowPassFilter.hpp"
#include "CAWLHighPassFilter.hpp"
#include "CAWLLowShelfFilter.hpp"
#include "CAWLHighShelfFilter.hpp"
#include "CAWLPeakFilter.hpp"
#include "CAWLAmpSimulator.hpp"
#include "CAWLSineWaveOsc.hpp"
#include "CAWLFlanger.hpp"
#include "CAWLChorus.hpp"
#include "CAWLTriangleWaveOsc.hpp"
#include "CAWLBandPassFilter.hpp"
#include "CAWLWahWah.hpp"
#include "CAWLOverdrive.hpp"
#include "CAWLPhaser.hpp"
#include "CAWLFuzz.hpp"
#include "CAWLAllPassFilter.hpp"
#include "CAWLCompressor.hpp"
#include "CAWLReverb.hpp"
#include <iostream>
#include <fstream>

#define SCALE 0.3
#define WRITE_TO_FILE
//#define SHOW_DEBUG_SAMPLES
#define TEST_BIQUAD 0
#define TEST_COMB 0
#define TEST_OSC 0
#define TEST_MOD_DELAY 1


void getWhiteNoiseStream(float * stream);
void getRawGuitarStream(float * stream);

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	

	
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
    
    float *debugBuffer = (float *) calloc(153600, 153600 * sizeof(float));
    float *debugPtr = debugBuffer;
    
    int debugBufWriteCount = 0;
    int * debugCountPtr = &debugBufWriteCount;
    
    float whiteNoiseBuffer[44533];
    float * whiteBufferPtr = whiteNoiseBuffer;
    int whiteNoiseCount = 0, * ptrToWhteCout = &whiteNoiseCount;
	
	float guitarNoiseBuffer[120000];
	float *guitarBufferPtr = guitarNoiseBuffer;
	int guitarBuffCount = 0, * ptrToGuitarCount = &guitarBuffCount;

    CAWL * instance = CAWL::Instance();
    getWhiteNoiseStream(whiteNoiseBuffer);
	getRawGuitarStream(guitarNoiseBuffer);
    
#if 1
    CAWLLowPassFilter lpf; lpf.setCenterFreq(1000);
    CAWLHighPassFilter hpf; hpf.setCenterFreq(500);
    CAWLLowPassFilter * lpfPtr = &lpf;
    CAWLHighPassFilter * hpfPtr = &hpf;

	
	CAWLUniversalCombFilter ucf; ucf.setDelay(2.2675736961); ucf.setFeedbackGain(1.0);
//    CAWLUniversalCombFilter ucf; ucf.setDelay(517); ucf.setMixLevel(0.7); ucf.setFeedbackGain(1); ucf.setFeedForwardGain(1.0);
    CAWLUniversalCombFilter * ptrToUcf = &ucf;
//    CAWLFIRCombFilter fir;
//    CAWLFIRCombFilter *ptrToFir = &fir;
//    CAWLIIRCombFilter iir; iir.setDelay(2.2675736961);
//    CAWLIIRCombFilter *ptrToiir = &iir;
    CAWLAllPassFilter apf,  *apfPtr = &apf; apf.setCenterFreq(792);

    //EQ stuff
    CAWLLowShelfFilter lsf, * lsfPtr = &lsf;
    lsf.setCenterFreq(100); lsf.setGain(-20.0);
    CAWLHighShelfFilter hsf, * hsfPtr = &hsf;
    hsf.setCenterFreq(10000); hsf.setGain(10.0);
    CAWLPeakFilter pf, * pfPtr = &pf;
    pf.setQFactor(10); pf.setCenterFreq(440); pf.setGain(10.0);
    CAWLPeakFilter pf2, * pf2Ptr = &pf2;
	pf2.setQFactor(10); pf2.setCenterFreq(1320); pf2.setGain(10.0);
	
    CAWLBandPassFilter bp, * bpPtr = &bp; bp.setCenterFreq(5000); bp.setQFactor(10);

    CAWLValveTubeSimulator valveSim, valveSim2, valveSim3;
    CAWLValveTubeSimulator * ptrToValve = &valveSim, * ptrToValve2 = &valveSim2, *ptrToValve3 = &valveSim3;
    CAWLAmpSimulator ampSim(2), ampSim2(1), ampSim3(2);
    CAWLAmpSimulator * ptrToAmp = &ampSim, *ptrToAmp2 = &ampSim2, *ptrToAmp3 = &ampSim3;
    
    CAWLSineWaveOsc sineWav, * sineWavPtr = &sineWav;// sineWav.setFreq(440);
    CAWLTriangleWaveOsc triWav, * triWavPtr = &triWav; triWav.setWaveTableFreq(220);
    CAWLFlanger flanger, * flangerPtr=&flanger; flanger.setModulationSpeed(1.0);
    CAWLChorus chorus,* chorusPtr=&chorus; chorus.setModulationSpeed(0.25);
    CAWLWahWah wah, *wahPtr=&wah;
    CAWLOverdrive overdrive, * odPtr=&overdrive;
	CAWLPhaser phaser, * phaserPtr=&phaser; phaser.setModRate(1); phaser.setMixLevel(.8);
	CAWLFuzz fuzz, *fuzzPtr=&fuzz;
#endif
    CAWLCompressor compressor, *compPtr=&compressor;
    compressor.setAttackTime(25); compressor.setReleaseTime(200);
    compressor.setCompressorThreshold(-10); compressor.setCompressorRatio(3); compressor.setKneeLevel(10);
    CAWLReverb reverb, *rvrbPtr=&reverb;
	cawlBuffer inputChannel1 = (^(float * data,
								   const unsigned int numSamples){
        double j = *fc;
        for(int i = 0; i < numSamples; i++)
        {
            //ptrToBuf1[i] = data[i];
#if TEST_BIQUAD
            //Testing BiQuads
            if(*ptrToWhteCout < 44100 ) {
				data[i] = whiteBufferPtr[*ptrToWhteCout];
				(*ptrToWhteCout)++;
            }
            else {
                data[i] = 0.0;
            }
#elif TEST_COMB
            //To test IIR/UCF Filters
            if(j < 100 ) {
                data[i] = (float) sin (2 * M_PI * (j / cycleLength));
                j += 1.0;
                if (j > cycleLength)
                    j -= cycleLength;
            }
            else {
                data[i] = 0.0;
            }
#elif TEST_OSC
            data[i] = sineWavPtr->getNextSample();
            //data[i] = triWavPtr->getNextSample();
#elif TEST_MOD_DELAY
			//Testing BiQuads
			if(*ptrToGuitarCount < 109363 ) {
				data[i] = guitarBufferPtr[*ptrToGuitarCount];
				(*ptrToGuitarCount)++;
			}
			else {
				*ptrToGuitarCount = 0;
				data[i] = guitarBufferPtr[*ptrToGuitarCount];
			}
#endif
        }
        *fc = j;


        //ptrToFir->processBuffer(data, numSamples);
//        ptrToiir->processBuffer(data, numSamples);
//        ptrToUcf->processBuffer(data, numSamples);
//        ptrToAmp->processBuffer(data, numSamples);
//        lsfPtr->processBuffer(data, numSamples);
//        hsfPtr->processBuffer(data, numSamples);
//        pfPtr->processBuffer(data, numSamples);
//        pf2Ptr->processBuffer(data, numSamples);
		
//        lpfPtr->processBuffer(data, numSamples);
//        hpfPtr->processBuffer(data, numSamples);
//        flangerPtr->processBuffer(data, numSamples);
//        chorusPtr->processBuffer(data,numSamples);
//        bpPtr->processBuffer(data, numSamples);
//       wahPtr->processBuffer(data, numSamples);
//        ptrToValve->processBuffer(data,numSamples);
//        odPtr->processBuffer(data, numSamples);
//        phaserPtr->processBuffer(data, numSamples);
//        fuzzPtr->processBuffer(data, numSamples);
//        compPtr->processBuffer(data, numSamples);
        rvrbPtr->processBuffer(data, numSamples);
//        apfPtr->processBuffer(data, numSamples);
#ifdef WRITE_TO_FILE
        if(*debugCountPtr < 300) {
            memcpy(debugPtr + (*debugCountPtr) * numSamples, data, (512 *sizeof(float)));
            (*debugCountPtr)++;
        }
#endif
        
	});
	
	cawlBuffer inputChannel2 = (^(float * data,
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
//        ptrToAmp2->processBuffer(data, numSamples);
        //ptrToValve2->processBuffer(data, numSamples);
//		*fc2 = j;
		//printf("%f ",j);
	});
    
    cawlBuffer inputChannel3 = (^(float * data,
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
//        ptrToAmp3->processBuffer(data, numSamples);
        //ptrToValve3->processBuffer(data, numSamples);
        //printf("%f ",j);
    });
	
    cawlBuffer inputChannel4 = (^(float * data, const unsigned int numSamples){
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
            
            //ampSim.setCutOff(2000.0);
            //std::cout << "new gain level " << ampSim.getGain() << std::endl;
        }
        if(c == '-'){
            //ampSim.setCutOff(10.0);
            //ampSim.setPreampGain(0.1);
            //std::cout << "new gain level " << ampSim.getGain() << std::endl;
        }
	}
#ifdef WRITE_TO_FILE
    std::ofstream out;
    out.open("/Users/moseslee/Desktop/delayfloat1", std::ios::out | std::ios::binary);
    out.write(reinterpret_cast <const char*> (debugBuffer) , 153600 * sizeof(float));
    out.close();
#endif
#ifdef SHOW_DEBUG_SAMPLES
    for(int i =0; i <153600; i++)
    {
        printf("%f\n", debugBuffer[i]);
    }
#endif
    delete [] debugBuffer;
    return 0;
    
}


void getWhiteNoiseStream(float * stream)
{
    FILE * file;
    std::string path = "/Users/moseslee/Desktop/CAWL/whiteNoiseRaw.aiff";
    file = fopen(path.c_str(), "r");
    
    float temp;
    
    if(file != NULL){
        int i = 0;
        while(!feof(file)){
            fread((void *)(&temp), sizeof(temp), 1, file);
            stream[i] = temp;
            i++;
        }
    }
}

void getRawGuitarStream(float * stream)
{
	FILE * file;
	std::string path = "/Users/moseslee/Desktop/CAWL/guitar1.raw";
    //std::string path = "/Users/moseslee/Desktop/loud_guitar.raw";
	file = fopen(path.c_str(), "r");
	
	float temp;
	
	if(file != NULL){
		int i = 0;
		while(!feof(file)){
			fread((void *)(&temp), sizeof(temp), 1, file);
			stream[i] = temp;
			i++;
		}
		printf("%d samples read\n", i);
	}
}




