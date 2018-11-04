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

#include <Block.h>

//#define MYBUFFER
#ifndef MYBUFFER
#include "CARingBuffer.h"
#else
#include "CAWLRingBuffer.hpp"
#endif
#include "CAWLAudioUnit.hpp"

typedef void (^cawlBuffer)(float * buffer,
							const unsigned int numSamples);


class CAWL
{
	//Public methods
public:
	cawlBuffer getInputBufferAtChannel(const unsigned int channel);
	bool registerInputBlockAtInputChannel(cawlBuffer buffer, const unsigned int channel);
	static CAWL * Instance();
	void startPlaying();
	void stopPlaying();
	
    int getNumChannels() { return numInputChannels; }
    
	//Enforce singleton pattern
	CAWL(CAWL const&)            = delete;
	void operator=(CAWL const&)  = delete;
	
	
	//Private methods
private:
	CAWL();
	~CAWL();
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
    
	//__weak cawlBuffer * sampleBuffer;
    __weak cawlBuffer * sampleBuffer;
	
    CAWLAudioUnit * aggregateAudioUnit;
	AUGraph graph;

	Float64 firstInputSampleTime;
	Float64 firstOutputSampleTime;
	Float64 inToOutSampleTimeOffset;
	AudioBufferList * inputBuffer;

	unsigned int numInputChannelsRegistered;
    unsigned int numInputChannels;
#ifndef MYBUFFER
	CARingBuffer * ringBuffer;
#else
	CAWLRingBuffer * ringBuffer;
#endif
	
};

#endif
