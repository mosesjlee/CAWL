//
//  CAWLFlanger.hpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLFlanger_hpp
#define CAWLFlanger_hpp
#include "CAWLDelayEffect.hpp"
#include "CAWLSineWaveOsc.hpp"

class CAWLFlanger : public CAWLDelayEffect
{
public:
	CAWLFlanger();
	~CAWLFlanger();
	void setModulationDepth();
	void setMixLevel();
	void setModulationSpeed();
private:
	CAWLSineWaveOsc * sine;
};

#endif /* CAWLFlanger_hpp */
