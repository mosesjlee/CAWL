//
//  DebugUtilities.cpp
//  cawlDemoMac
//
//  Created by Moses Lee on 12/24/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "DebugUtilities.hpp"
#include <string>

#define WRITE_TO_FILE
//#define SHOW_DEBUG_SAMPLES
#define TEST_BIQUAD 0
#define TEST_COMB 0
#define TEST_OSC 0
#define TEST_MOD_DELAY 1

float whiteNoiseBuffer[44533];
float * whiteBufferPtr = whiteNoiseBuffer;
int whiteNoiseCount = 0, * ptrToWhteCout = &whiteNoiseCount;

float guitarNoiseBuffer[120000];
float *guitarBufferPtr = guitarNoiseBuffer;
int guitarBuffCount = 0, * ptrToGuitarCount = &guitarBuffCount;



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

void fillGuitarStream()
{
    getRawGuitarStream(guitarNoiseBuffer);
}

void fillWhiteNoiseStream()
{
    getWhiteNoiseStream(whiteNoiseBuffer);
}

cawlBuffers testBuffer = (^(float * data, const unsigned int numSamples){
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
});
