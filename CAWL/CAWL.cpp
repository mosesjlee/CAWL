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

//The static instance
CAWL * CAWL::cawlInstance;

CAWL::CAWL()
{
	numInputChannelsRegistered = 0;
	setupAudioInputUnits();
	setupGraph();
}

CAWL::~CAWL()
{
	
	//Free buffers
	
	//AUGraph clean up
	cleanUp();
	
	//delete instance
	delete cawlInstance;
}

CAWL * CAWL::Instance()
{
	//static CAWL * instance;
	if(cawlInstance == NULL) cawlInstance = new CAWL();
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
	
	printf("Number of input channels: %d\n", this->streamFormat.mChannelsPerFrame);
	numInputChannels = this->streamFormat.mChannelsPerFrame;
	this->input = new cawlBuffers[numInputChannels];
	
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

void CAWL::setupGraph()
{
	//Initialize the new graph
	CheckError(NewAUGraph(&this->graph),
			   "Could not create graph");
	
	//Generate a description that matches the default output
	AudioComponentDescription outputcd = {0};
	outputcd.componentType = kAudioUnitType_Output;
	outputcd.componentSubType = kAudioUnitSubType_DefaultOutput;
	outputcd.componentManufacturer = kAudioUnitManufacturer_Apple;
	
	AudioComponent comp = AudioComponentFindNext(NULL, &outputcd);
	if(comp == NULL)
	{
		printf("Can't get audio component");
		exit(-1);
	}
	
	AUNode outputNode;
	CheckError(AUGraphAddNode(this->graph,
							  &outputcd,
							  &outputNode),
			   "Could not add output node");
	
	//Open the graph
	CheckError(AUGraphOpen(this->graph),
			   "Could not open graph");
	
	//Get reference to the AudioUnit object for the graph
	CheckError(AUGraphNodeInfo(this->graph,
							   outputNode,
							   NULL,
							   &this->outputUnit),
			   "Could not get reference to the output Audio Unit");
	
	//Set the stream format on the output unit's input scope
	UInt32 propSize = sizeof(AudioStreamBasicDescription);
	CheckError(AudioUnitSetProperty(this->outputUnit,
									kAudioUnitProperty_StreamFormat,
									kAudioUnitScope_Input,
									0,
									&this->streamFormat,
									propSize),
			   "Couldnt set stream format on output unit");
	
	AURenderCallbackStruct callbackStruct;
	callbackStruct.inputProc = &CAWL::OutputRenderCallBack;
	callbackStruct.inputProcRefCon = this;
	
	CheckError(AudioUnitSetProperty(this->outputUnit,
									kAudioUnitProperty_SetRenderCallback,
									kAudioUnitScope_Global,
									0,
									&callbackStruct,
									sizeof(callbackStruct)),
			   "Couldnt set render callback on output unit");
	
	//Now initialize the graph
	CheckError(AUGraphInitialize(this->graph),
			   "Could not initialize graph");
	
	this->firstOutputSampleTime = -1;
}

//Clean up the graphs and shiz
void CAWL::cleanUp()
{
	AUGraphStop(this->graph);
	AUGraphUninitialize(this->graph);
	AUGraphClose(this->graph);
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
	
	//offset calculation
	if(instance->firstInputSampleTime < 0.0)
	{
		instance->firstInputSampleTime = inTimeStamp->mSampleTime;
		if ((instance->firstOutputSampleTime > -1.0) &&
			(instance->inToOutSampleTimeOffset < 0.0))
		{
			instance->inToOutSampleTimeOffset =
			instance->firstInputSampleTime - instance->firstOutputSampleTime;
		}
	}
	
	OSStatus error = noErr;
	
	error = AudioUnitRender(instance->inputUnit,
							ioActionFlags,
							inTimeStamp,
							inBusNumber,
							inNumberFrames,
							instance->inputBuffer);
	
	//There should be no post processing done here. You should store it ASAP to the ring buffer
	
	if(!error)
	{
		error = instance->ringBuffer->Store(instance->inputBuffer,
											inNumberFrames,
											inTimeStamp->mSampleTime);
	}
	
	return error;
}

OSStatus CAWL::OutputRenderCallBack(void *inRefCon,
									 AudioUnitRenderActionFlags * ioActionFlags,
									 const AudioTimeStamp *inTimeStamp,
									 UInt32 inBusNumber,
									 UInt32 inNumberFrames,
									 AudioBufferList * ioData)
{
	CAWL * instance = (CAWL *) inRefCon;
	
	
	//offset calculation
	if(instance->firstOutputSampleTime < 0.0)
	{
		instance->firstOutputSampleTime = inTimeStamp->mSampleTime;
		if ((instance->firstOutputSampleTime > -1.0) &&
			(instance->inToOutSampleTimeOffset < 0.0))
		{
			instance->inToOutSampleTimeOffset =
			instance->firstInputSampleTime - instance->firstOutputSampleTime;
		}
	}
	
	OSStatus error = noErr;
	
	
	error = instance->ringBuffer->Fetch(ioData,
										inNumberFrames,
										inTimeStamp->mSampleTime +
										instance->inToOutSampleTimeOffset);
	
	
	
	//This is where you can do some post processing
	//For now i am just screwingaround in here to see what is possible
	
//	if(instance->numInputChannelsRegistered > 0)
//	{
//		for(unsigned i = 0; i < instance->numInputChannels; i++)
//		{
//			float * buf = (float *) ioData->mBuffers[i].mData;
//			instance->input[i](buf, inNumberFrames);
//		}
//	}
	
	return error;
}

cawlBuffers CAWL::getInputBufferAtChannel(const unsigned int channel)
{
	if(channel > numInputChannels)
		return nullptr;
	
	return input[channel];
}

bool CAWL::registerInputBlockAtInputChannel(cawlBuffers buffer, const unsigned int channel)
{
	if(channel > numInputChannels)
		return false;
	
	input[channel] = buffer;
	numInputChannelsRegistered++;
	return true;
}

void CAWL::startPlaying()
{
	CheckError(AudioOutputUnitStart(this->inputUnit),
			   "AudioOutputUnitStart failed");
	CheckError(AUGraphStart(this->graph),
			   "AUGraphStart failed");
}

void CAWL::stopPlaying()
{
	CheckError(AudioOutputUnitStop(this->inputUnit),
			   "AudioOutputUnitStart failed");
	CheckError(AUGraphStop(this->graph),
			   "AUGraphStart failed");
}






