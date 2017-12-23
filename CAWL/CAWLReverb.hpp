//
//  CAWLReverb.hpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLReverb_hpp
#define CAWLReverb_hpp

#define NUM_MOORERS_DELAYLINE 6

#include "CAWLDelayLine.hpp"
#include "CAWLLowPassFilter.hpp"
#include "CAWLHighShelfFilter.hpp"

class CAWLReverb
{
public:
    CAWLReverb();
    ~CAWLReverb();
    void processBuffer(float * AudioStreamBuf, const unsigned int numSamples);
    void setReverbTime(double newTime);
    void setReverbMix(double newMix);
	void adjustReverbTone(double newToneLevel);
    
private:
    CAWLDelayLine *cCombDelayLineArray;
    CAWLDelayLine cApDelayLine;
	CAWLHighShelfFilter cToneControl;
    double cDelayLineOut[NUM_MOORERS_DELAYLINE];
    double cDelayLineZ_1[NUM_MOORERS_DELAYLINE];
    double cLpfZ_1Samples[NUM_MOORERS_DELAYLINE];
    double cLpfGain[NUM_MOORERS_DELAYLINE];
    double cCombGain[NUM_MOORERS_DELAYLINE];
    double cApGain;
    double cApOut;
    double cReverbTime;
    double cReverbMix;
};

#endif /* CAWLReverb_hpp */
