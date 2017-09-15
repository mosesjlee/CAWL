//
//  CAWLAudioUnit.hpp
//  CAWL
//
//  Created by Moses Lee on 9/14/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLAudioUnit_hpp
#define CAWLAudioUnit_hpp

#include <stdio.h>
#include <CoreAudio/CoreAudio.h>
#include <AudioToolbox/AudioToolbox.h>
#include <AudioUnit/AudioUnit.h>

class CAWLAudioUnit
{
private:
	AudioUnit inputUnit;
	AudioUnit outputUnit;
	AudioStreamBasicDescription aggregateASBD;
	Float64 sampleRate;
	UInt32 numOfChannels;
	
	OSStatus setDefaultInputAudioUnit();
	OSStatus setupAudioUnitIO();
	
public:
	CAWLAudioUnit();
	~CAWLAudioUnit();
    UInt32 getNumOfChannels() { return numOfChannels; }
    Float64 getSampleRate() { return sampleRate; }
    AudioUnit getInputUnit() { return inputUnit; }
    AudioUnit getOutputUnit() { return outputUnit; }
    AudioStreamBasicDescription getASBD() { return aggregateASBD; }
};
#endif /* CAWLAudioUnit_hpp */
