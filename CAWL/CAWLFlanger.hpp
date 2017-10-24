//
//  CAWLFlanger.hpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLFlanger_hpp
#define CAWLFlanger_hpp
#include "CAWLIIRCombFilter.hpp"
#include "CAWLSineWaveOsc.hpp"

class CAWLFlanger : public CAWLIIRCombFilter
{
public:
	CAWLFlanger();
	~CAWLFlanger();
	void setModulationDepth(double newModDepth);
	void setMixLevel(double mixLevel);
	void setModulationSpeed(double newModSpeed);
    void processBuffer(float * buf, const unsigned int numSamples);
	double flangedValue();
private:
	CAWLSineWaveOsc * sine;
    double modDepth;
    double modSpeed;
	double mixLevel;
};

#endif /* CAWLFlanger_hpp */
