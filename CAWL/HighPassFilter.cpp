//
//  simpleEq.cpp
//  SimpleOsc
//
//  Created by Moses Lee on 1/13/16.
//  Copyright © 2016 Moses Lee. All rights reserved.
//

#include "HighPassFilter.hpp"
HighPassFilter::HighPassFilter(){
    for (int i = 0; i < 512; i++) {
        inputBuf[i] = 0.0;
        outputBuf[i] = 0.0;
    }
    inputReadIndex = 0;
    minus_1_index = 512 - 1;
    minus_2_index = 512 - 2;
    
    outputWriteIndex = 0;
    output_minus_1_index = 512 - 1;
    output_minus_2_index = 512 - 2;
}

HighPassFilter::~HighPassFilter(){

}

void HighPassFilter::calculateCoeff(){
    theta_c = (2 * M_PI * cutOffFrequency)/ (float) 44100;
    gamma = cos(theta_c)/(1 + sin(theta_c));
    a_0 = (1+gamma)/2;
    a_1 = -1 * (1+gamma)/2;
    b_1 = gamma * -1.0;
}

void HighPassFilter::changeCutOffFreq(float newFreq){
    cutOffFrequency = newFreq;
    calculateCoeff();
}


void HighPassFilter::fillInputBuffer(float * buf, int numSamples, int numChannels){
    for (int i = 0; i < numSamples; i++) {
        inputBuf[inputWriteIndex] =  buf[i];
        inputWriteIndex = (inputWriteIndex + 1) % 512;
    }
}

float * HighPassFilter::getInputBuffer(){
    return inputBuf;
}

void HighPassFilter::fillOutputBuffer(float * buf, int numSamples, int numChannels){
    for (int i = 0; i < numSamples; i++) {
        for (int j = 0; j < 1; j++){
            buf[i * numChannels + j] = outputBuf[i];
        }
        outputReadIndex = (outputReadIndex + 1) % 512;
    }
}

void HighPassFilter::processNextSamples(){
    for (int i = 0; i < 512; i++) {
        
        a_0_xn = a_0 * inputBuf[i];
        a_1_xn_1 = a_1 * inputBuf[minus_1_index];
        a_2_xn_2 = a_2 * inputBuf[minus_2_index];
        
        inputReadIndex = (inputReadIndex + 1) % 512;
        minus_1_index = (minus_1_index + 1) % 512;
        minus_2_index = (minus_2_index + 1) % 512;
        
        b_1_yn_1 = b_1 * outputBuf[output_minus_1_index];
        b_2_yn_2 = b_2 * outputBuf[output_minus_2_index];
        
        output_minus_1_index = (output_minus_1_index + 1) % 512;
        output_minus_2_index = (output_minus_2_index + 1) % 512;
        
        float val = a_0_xn + a_1_xn_1 + a_2_xn_2 - b_1_yn_1 - b_2_yn_2;
        
        val = val > 1.0 ? 1.0 : val;
        val = val < -1.0 ? -1.0 : val;
        //std::cout << "Val: " << val << std::endl;
        
        outputBuf[i] = val;
        outputWriteIndex = (outputWriteIndex + 1) % 512;
    }
}




