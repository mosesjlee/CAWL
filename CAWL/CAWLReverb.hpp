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
    void processBuffer(float * buf, const unsigned int numSamples);
    void setReverbTime(double newTime);
    void setReverbMix(double newMix);
	void adjustReverbTone(double newToneLevel);
private:
    CAWLDelayLine *combDelayLineArray;
    CAWLDelayLine apDelayLine;
	CAWLHighShelfFilter toneControl;
    double delayLineOut[NUM_MOORERS_DELAYLINE];
    double delayLineZ_1[NUM_MOORERS_DELAYLINE];
    double lpfZ_1Samples[NUM_MOORERS_DELAYLINE];
    double lpfGain[NUM_MOORERS_DELAYLINE];
    double combGain[NUM_MOORERS_DELAYLINE];
    double apGain;
    double apOut;
    double reverbTime;
    double reverbMix;
};

#endif /* CAWLReverb_hpp */
