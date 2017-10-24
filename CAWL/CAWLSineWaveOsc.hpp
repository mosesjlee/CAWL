//
//  CAWLSineWaveOsc.hpp
//  CAWL
//
//  Created by Moses Lee on 10/23/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLSineWaveOsc_hpp
#define CAWLSineWaveOsc_hpp

class CAWLSineWaveOsc
{
public:
	CAWLSineWaveOsc();
	~CAWLSineWaveOsc();
	double getNextSample();
private:
	double sampleRate;
	double freq;
};

#endif /* CAWLSineWaveOsc_hpp */
