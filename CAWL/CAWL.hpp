/*
 *  CAWL.hpp
 *  CAWL
 *
 *  Created by Moses Lee on 10/31/16.
 *  Copyright © 2016 Moses Lee. All rights reserved.
 *
 */

#ifndef CAWL_
#define CAWL_
#include <TargetConditionals.h>


#include <CoreAudio/CoreAudio.h>
#include <AudioToolbox/AudioToolbox.h>
#include <AudioUnit/AudioUnit.h>
#include <Block.h>

//#define MYBUFFER
#ifndef MYBUFFER
#include "CARingBuffer.h"
#else
#include "CAWLRingBuffer.hpp"
#endif

typedef void (^cawlBuffers)(float * buffer,
							const unsigned int numSamples);

class CAWL
{
	//Public methods
public:
	cawlBuffers getInputBufferAtChannel(const unsigned int channel);
	bool registerInputBlockAtInputChannel(cawlBuffers buffer, const unsigned int channel);
	static CAWL * Instance();
	void startPlaying();
	void stopPlaying();
	
	//Enforce singleton pattern
	CAWL(CAWL const&)            = delete;
	void operator=(CAWL const&)  = delete;
	
	
	//Private methods
private:
	CAWL();
	~CAWL();
	void setupAudioInputUnits();
	void setupGraph();
    void setupBuffers();
	void cleanUp();
	
	static OSStatus InputRenderCallBack(void *inRefCon,
								 AudioUnitRenderActionFlags * ioActionFlags,
								 const AudioTimeStamp *inTimeStamp,
								 UInt32 inBusNumber,
								 UInt32 inNumberFrames,
								 AudioBufferList * ioData);
	static OSStatus OutputRenderCallBack(void *inRefCon,
										 AudioUnitRenderActionFlags * ioActionFlags,
										 const AudioTimeStamp *inTimeStamp,
										 UInt32 inBusNumber,
										 UInt32 inNumberFrames,
										 AudioBufferList * ioData);
    
    
	
	
	//Member variables
private:
	static CAWL * cawlInstance;
	float sampleRate;
	cawlBuffers * input;
	cawlBuffers * output;
	
	AudioStreamBasicDescription streamFormat;
	AUGraph graph;
	AudioUnit inputUnit;
	AudioUnit outputUnit;
	
	Float64 firstInputSampleTime;
	Float64 firstOutputSampleTime;
	Float64 inToOutSampleTimeOffset;
	AudioBufferList * inputBuffer;
    float outputTest[132300];
	unsigned int numInputChannels;
	unsigned int numInputChannelsRegistered;
	
#ifndef MYBUFFER
	CARingBuffer * ringBuffer;
#else
	CAWLRingBuffer * ringBuffer;
#endif
	
};

#endif
