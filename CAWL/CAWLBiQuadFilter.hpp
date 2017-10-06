//
//  CAWLBiQuadFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 10/4/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLBiQuadFilter_hpp
#define CAWLBiQuadFilter_hpp

#include <stdio.h>
#include "CAWLDelayLine.hpp"
#include "CAWLSoundModule.hpp"

class CAWLBiQuadFilter : public CAWLSoundModule
{
public:
    CAWLBiQuadFilter();
    ~CAWLBiQuadFilter();
	virtual void processBuffer(float * buf, const unsigned int numSamples);
    
protected:
    CAWLDelayLine firstOrderDelayLine, secondOrderDelayLine;
	float a_0, a_1, a_2, b_1, b_2, c_0, d_0;
    
private:
	//Intermediary values for signal processing
	float x_a_0 = 0.0, x_a_1 = 0.0, x_a_2 = 0.0;
	float x_b_1 = 0.0, x_b_2 = 0.0;
	
};

#endif /* CAWLBiQuadFilter_hpp */
