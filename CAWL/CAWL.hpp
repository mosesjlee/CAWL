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

#if TARGET_OS_IPHONE
#else
#include <CoreAudio/CoreAudio.h>
#endif

#include <AudioToolbox/AudioToolbox.h>

#include <Block.h>

//#define MYBUFFER
#ifndef MYBUFFER
#include "CARingBuffer.h"
#else
#include "CAWLRingBuffer.hpp"
#endif

typedef void (^cawlBuffers)(const unsigned int numChannels,
							float * buffer,
							const unsigned int numSamples);

class CAWL
{
	//Public methods
public:
	float * getInputBufferAtChannel(const unsigned int channel, unsigned int & numSamples);
	static CAWL * Instance();
	void startPlaying();
	
	//Enforce singleton pattern
	CAWL(CAWL const&)            = delete;
	void operator=(CAWL const&)  = delete;
	
	
	//Private methods
private:
	CAWL();
	~CAWL();
	void CheckError(OSStatus error, const char * operation);
	void setupAudioInputUnits();
	void setupGraph();
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
	unsigned int numChannels;
	float sampleRate;
	cawlBuffers input;
	cawlBuffers output;
	
	AudioStreamBasicDescription streamFormat;
	AUGraph graph;
	AudioUnit inputUnit;
	AudioUnit outputUnit;
	
	Float64 firstInputSampleTime;
	Float64 firstOutputSampleTime;
	Float64 inToOutSampleTimeOffset;
	AudioBufferList * inputBuffer;
	
	int startingFrameCount;
	
#ifndef MYBUFFER
	CARingBuffer * ringBuffer;
#else
	CAWLRingBuffer * ringBuffer;
#endif
	
};

#endif
