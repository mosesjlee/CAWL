/*
 *  CAWL.cpp
 *  CAWL
 *
 *  Created by Moses Lee on 10/31/16.
 *  Copyright © 2016 Moses Lee. All rights reserved.
 *
 */

#include <iostream>
#include "CAWL.hpp"

CAWL::CAWL()
{
	cawlInstance = NULL;
	setupAudioInputUnits();
}

CAWL::~CAWL()
{
	
	//Free buffers
	
	//Delete instance
}

CAWL * CAWL::Instance()
{
	if(cawlInstance == NULL)
	{
		cawlInstance = new CAWL();
	}
	
	return cawlInstance;
}

/**
 This function is copied from the book Learning CoreAudio
 Authors: Chris Adamson, Kevin Avila
 **/
void CAWL::CheckError(OSStatus error, const char * operation)
{
	if (error == noErr) return;
	
	char errorString[20];
	
	//See if it appears to be a 4 char-code
	*(UInt32 *) (errorString + 1) = CFSwapInt32HostToBig(error);
	if(isprint(errorString[1]) && isprint(errorString[2]) &&
	   isprint(errorString[3]) && isprint(errorString[4]))
	{
		errorString[0] = errorString[5] = '\'';
		errorString[6] = '\0';
	}
	//No, format it as an integer
	else
	{
		sprintf(errorString, "%d", (int) error);
	}
	
	fprintf(stderr, "Error: %s (%s)\n", operation, errorString);
	
	//May need a more graceful recovery
	exit(1);
}

/**
 Parts of this function is copied from the book Learning CoreAudio
 Authors: Chris Adamson, Kevin Avila
 **/
void CAWL::setupAudioInputUnits()
{
	//Generate a description
	AudioComponentDescription inputcd = {0};
	inputcd.componentType = kAudioUnitType_Output;
	inputcd.componentSubType = kAudioUnitSubType_HALOutput;
	inputcd.componentManufacturer = kAudioUnitManufacturer_Apple;
	
	AudioComponent comp = AudioComponentFindNext(NULL, &inputcd);
	if(comp == NULL)
	{
		printf("Can't get output unit\n");
		
		//May need a more gracious way of exitting
		exit(-1);
	}
	
	CheckError(AudioComponentInstanceNew(comp, &this->inputUnit),
			   "Couldn't open component for inputUnit");
	
	/***********************************************
		This section enables the input and
		disables the output for this AudioUnit
		that we designated as the input
	 ***********************************************/
	UInt32 disableFlag = 0;
	UInt32 enableFlag = 1;
	AudioUnitScope outputBus = 0;
	AudioUnitScope inputBus = 1;
	
	CheckError(AudioUnitSetProperty(this->inputUnit,
									kAudioOutputUnitProperty_EnableIO,
									kAudioUnitScope_Input,
									inputBus,
									&enableFlag,
									sizeof(enableFlag)),
			   "Couldn't enable input on I/O unit");
	
	CheckError(AudioUnitSetProperty(this->inputUnit,
									kAudioOutputUnitProperty_EnableIO,
									kAudioUnitScope_Output,
									outputBus,
									&disableFlag,
									sizeof(disableFlag)),
			   "Couldn't disable output on I/O unit");
	
	/***********************************************
		This next section specifies the audio
		device to get the audio input from
	 ***********************************************/
	AudioDeviceID defaultDevice = kAudioObjectUnknown;
	UInt32 propertySize = sizeof(defaultDevice);
	AudioObjectPropertyAddress defaultDeviceProperty;
	defaultDeviceProperty.mSelector = kAudioHardwarePropertyDefaultInputDevice;
	defaultDeviceProperty.mScope = kAudioObjectPropertyScopeGlobal;
	defaultDeviceProperty.mElement = kAudioObjectPropertyElementMaster;
	
	CheckError(AudioObjectGetPropertyData(kAudioObjectSystemObject,
										  &defaultDeviceProperty,
										  0,
										  NULL,
										  &propertySize,
										  &defaultDevice),
			   "Couldn't get default input device");
	
	CheckError(AudioUnitSetProperty(this->inputUnit,
									kAudioOutputUnitProperty_CurrentDevice,
									kAudioUnitScope_Global,
									outputBus,
									&defaultDevice,
									sizeof(defaultDevice)),
			   "Couldn't set default device on I/O unit");
	
	//Get the ASBD from Input AUHAL
	propertySize = sizeof(AudioStreamBasicDescription);
	CheckError(AudioUnitGetProperty(this->inputUnit,
									kAudioUnitProperty_StreamFormat,
									kAudioUnitScope_Output,
									inputBus,
									&this->streamFormat,
									&propertySize),
			   "Couldn't get ASBD from Input unit");
	
	//Adopt Hardware input sample
	AudioStreamBasicDescription deviceFormat;
	CheckError(AudioUnitGetProperty(this->inputUnit,
									kAudioUnitProperty_StreamFormat,
									kAudioUnitScope_Input,
									inputBus,
									&deviceFormat,
									&propertySize),
			   "Couldn't get ASBD from input unit");
	
	this->streamFormat.mSampleRate = deviceFormat.mSampleRate;
	
	propertySize = sizeof(AudioStreamBasicDescription);
	CheckError(AudioUnitSetProperty(this->inputUnit,
									kAudioUnitProperty_StreamFormat,
									kAudioUnitScope_Output,
									inputBus,
									&this->streamFormat,
									propertySize),
			   "Couldn't set ASBD on input unit");
	
	//Calculate Capture buffer size for an I/O unit
	UInt32 bufferSizeFrames = 0;
	propertySize = sizeof(UInt32);
	CheckError(AudioUnitGetProperty(this->inputUnit,
									kAudioDevicePropertyBufferSize,
									kAudioUnitScope_Global,
									0,
									&bufferSizeFrames,
									&propertySize),
			   "Couldn't get buffer frame size from input unit");
	
	UInt32 bufferSizeBytes = bufferSizeFrames * sizeof(Float32);
	
	//Create an AudioBufferList to receive Capture Data
	UInt32 propSize = offsetof(AudioBufferList, mBuffers[0]) +
						(sizeof(AudioBuffer) * this->streamFormat.mChannelsPerFrame);
	
	//Malloc buffer lists
	this->inputBuffer = (AudioBufferList *) malloc(propSize);
	this->inputBuffer->mNumberBuffers = this->streamFormat.mChannelsPerFrame;
	
	//Premalloc buffers for AudioBufferLists
	for(unsigned i = 0; i < this->inputBuffer->mNumberBuffers; i++)
	{
		this->inputBuffer->mBuffers[i].mNumberChannels = 1;
		this->inputBuffer->mBuffers[i].mDataByteSize = bufferSizeBytes;
		this->inputBuffer->mBuffers[i].mData = malloc(bufferSizeBytes);
	}
	
	//Allocate a ring buffer
	this->ringBuffer = new CARingBuffer();
	this->ringBuffer->Allocate(this->streamFormat.mChannelsPerFrame,
							   this->streamFormat.mBytesPerFrame,
							   bufferSizeFrames * 3);
	
	//Set up Input callback on an AUHAL
	AURenderCallbackStruct callbackStruct;
	callbackStruct.inputProc = &CAWL::InputRenderCallBack;
	callbackStruct.inputProcRefCon = this;
	
	CheckError(AudioUnitSetProperty(this->inputUnit,
									kAudioOutputUnitProperty_SetInputCallback,
									kAudioUnitScope_Global,
									0,
									&callbackStruct,
									sizeof(callbackStruct)),
			   "Couldn't set input callback");
	
	//Initialize
	CheckError(AudioUnitInitialize(this->inputUnit),
			   "Couldn't initialize input unit");
	
	firstInputSampleTime = -1;
	inToOutSampleTimeOffset = -1;
	
	printf("Finished setting up input unit\n");
}

//Callbacks
OSStatus CAWL::InputRenderCallBack(void *inRefCon,
							 AudioUnitRenderActionFlags * ioActionFlags,
							 const AudioTimeStamp *inTimeStamp,
							 UInt32 inBusNumber,
							 UInt32 inNumberFrames,
							 AudioBufferList * ioData)
{
	CAWL * instance = (CAWL *) inRefCon;
	
	OSStatus error = noErr;
	return error;
}







