//
//  simpleEq.hpp
//  SimpleOsc
//
//  Created by Moses Lee on 1/13/16.
//  Copyright © 2016 Moses Lee. All rights reserved.
//

#ifndef HighPassFilter_hpp
#define HighPassFilter_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>

class HighPassFilter {
private:
    float theta_c;
    float gamma;
    float a_0;
    float a_1;
    float a_2 = 0.0;
    float b_1;
    float b_2 = 0.0;
    float y_n;
    float x_n;
    float a_0_xn;
    float a_1_xn_1;
    float a_2_xn_2;
    float b_1_yn_1;
    float b_2_yn_2;
    float inputBuf[512];
    float outputBuf[512];
    int inputReadIndex;
    int inputWriteIndex;
    int minus_1_index;
    int minus_2_index;
    int outputReadIndex;
    int outputWriteIndex;
    int output_minus_1_index;
    int output_minus_2_index;
    float cutOffFrequency;
    
public:
    HighPassFilter();
    ~HighPassFilter();
    void processNextSamples();
    void calculateCoeff();
    float calculateGamma();
    void fillInputBuffer(float * buf, int numSamples, int numChannels);
    float * getInputBuffer();
    void fillOutputBuffer(float * buf, int numSamples, int numChannels);
    void changeCutOffFreq(float newFreq);
};

#endif /* simpleEq_hpp */
