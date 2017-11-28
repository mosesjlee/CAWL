//
//  CAWLReverb.hpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLReverb_hpp
#define CAWLReverb_hpp
#include "CAWLDelayLine.hpp"
#include "CAWLHighShelfFilter.hpp"
class CAWLReverb
{
public:
    CAWLReverb();
    ~CAWLReverb();
    void processBuffer(float * buf, const unsigned int numSamples);
	void adjustReverbTone(double newToneLevel);
private:
    CAWLDelayLine ** delayLineArray;
	CAWLHighShelfFilter toneControl;
};

#endif /* CAWLReverb_hpp */
