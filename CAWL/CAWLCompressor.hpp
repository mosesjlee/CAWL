//
//  CAWLCompressor.hpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLCompressor_hpp
#define CAWLCompressor_hpp
#include "CAWLDelayLine.hpp"

class CAWLCompressor
{
public:
    CAWLCompressor();
    ~CAWLCompressor();
    void processBuffer(float * buf, const unsigned int numSamples);
    void setAttackTime(double newAttackTime);
    void setReleaseTime(double newReleaseTime);
    void setCompressorThreshold(double newThreshold);
    void setCompressorRatio(double newRatio);
    void setKneeLevel(double newKneeLevel);
    void setMakeUpGain(double newMakeupGain);
private:
    double min(double x, double y);
    double calculateKneeGain(double sample);
    double attackTime;
    double releaseTime;
    double attackCoeff;
    double releaseCoeff;
    double compressorThreshold;
    double compressorRatio;
    double compressorSlope;
    double averageTime;
    double xrms;
    double gain;
    double kneeLevel;
    double numeratorValue;
    double makeupGain;
    CAWLDelayLine delayLine;
};

#endif /* CAWLCompressor_hpp */
