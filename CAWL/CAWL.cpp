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
#include "CAWLUtilities.hpp"
//The static instance
CAWL * CAWL::cawlInstance;

CAWL::CAWL()
{
    aggregateAudioUnit = new CAWLAudioUnit();
    setupBuffers();
	setupGraph();
    
    firstInputSampleTime = -1;
    inToOutSampleTimeOffset = -1;
    firstOutputSampleTime = -1;
}

CAWL::~CAWL()
{
	//Free buffers
	
    
	//AUGraph clean up
	cleanUp();
    
	//delete instance
    delete aggregateAudioUnit;
	delete cawlInstance;
}

CAWL * CAWL::Instance()
{
	//static CAWL * instance;
	if(cawlInstance == NULL) cawlInstance = new CAWL();
	return cawlInstance;
}


/**
 Parts of this function is copied from the book Learning CoreAudio
 Authors: Chris Adamson, Kevin Avila
 **/
void CAWL::setupBuffers()
{
	//Calculate Capture buffer size for an I/O unit
	UInt32 bufferSizeFrames = 0;
	UInt32 propertySize = sizeof(UInt32);
	CheckError(AudioUnitGetProperty(aggregateAudioUnit->getInputUnit(),
									kAudioDevicePropertyBufferSize,
									kAudioUnitScope_Global,
									0,
									&bufferSizeFrames,
									&propertySize),
			   "Couldn't get buffer frame size from input unit");
	
	UInt32 bufferSizeBytes = bufferSizeFrames * sizeof(Float32);
	
	//Create an AudioBufferList to receive Capture Data
	UInt32 propSize = offsetof(AudioBufferList, mBuffers[0]) +
						(sizeof(AudioBuffer) * aggregateAudioUnit->getASBD().mChannelsPerFrame);
	
	//Malloc buffer lists
	inputBuffer = (AudioBufferList *) malloc(propSize);
	inputBuffer->mNumberBuffers = aggregateAudioUnit->getASBD().mChannelsPerFrame;
	
	//Premalloc buffers for AudioBufferLists
	for(unsigned i = 0; i < this->inputBuffer->mNumberBuffers; i++)
	{
		inputBuffer->mBuffers[i].mNumberChannels = 1;
		inputBuffer->mBuffers[i].mDataByteSize = bufferSizeBytes;
		inputBuffer->mBuffers[i].mData = malloc(bufferSizeBytes);
	}
	
	printf("Number of input channels: %d\n", aggregateAudioUnit->getASBD().mChannelsPerFrame);
	numInputChannels = aggregateAudioUnit->getASBD().mChannelsPerFrame;
	input = new cawlBuffers[numInputChannels];
	
	//Allocate a ring buffer
	ringBuffer = new CARingBuffer();
	ringBuffer->Allocate(aggregateAudioUnit->getASBD().mChannelsPerFrame,
                        aggregateAudioUnit->getASBD().mChannelsPerFrame,
                        bufferSizeFrames * 3);
	
	//Set up Input callback on an AUHAL
	AURenderCallbackStruct callbackStruct;
	callbackStruct.inputProc = &CAWL::InputRenderCallBack;
	callbackStruct.inputProcRefCon = this;
	
	CheckError(AudioUnitSetProperty(aggregateAudioUnit->getInputUnit(),
									kAudioOutputUnitProperty_SetInputCallback,
									kAudioUnitScope_Global,
									0,
									&callbackStruct,
									sizeof(callbackStruct)),
			   "Couldn't set input callback");
	
	//Initialize
	CheckError(AudioUnitInitialize(aggregateAudioUnit->getInputUnit()),
			   "Couldn't initialize input unit");
	
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
	
    AudioUnit output = aggregateAudioUnit->getOutputUnit();
    AudioStreamBasicDescription asbd = aggregateAudioUnit->getASBD();
    
	//Get reference to the AudioUnit object for the graph
	CheckError(AUGraphNodeInfo(this->graph,
							   outputNode,
							   NULL,
							   &output),
			   "Could not get reference to the output Audio Unit");
	
	//Set the stream format on the output unit's input scope
	UInt32 propSize = sizeof(AudioStreamBasicDescription);
	CheckError(AudioUnitSetProperty(output,
									kAudioUnitProperty_StreamFormat,
									kAudioUnitScope_Input,
									0,
									&asbd,
									propSize),
			   "Couldnt set stream format on output unit");
	
	AURenderCallbackStruct callbackStruct;
	callbackStruct.inputProc = &CAWL::OutputRenderCallBack;
	callbackStruct.inputProcRefCon = this;
	
	CheckError(AudioUnitSetProperty(output,
									kAudioUnitProperty_SetRenderCallback,
									kAudioUnitScope_Global,
									0,
									&callbackStruct,
									sizeof(callbackStruct)),
			   "Couldnt set render callback on output unit");
	
	//Now initialize the graph
	CheckError(AUGraphInitialize(this->graph),
			   "Could not initialize graph");

}

//Clean up the graphs and shiz
void CAWL::cleanUp()
{
	AUGraphStop(graph);
	AUGraphUninitialize(graph);
	AUGraphClose(graph);
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
	
	error = AudioUnitRender(instance->aggregateAudioUnit->getInputUnit(),
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
    float * buffers[instance->numInputChannels];
	if(instance->numInputChannelsRegistered > 0)
	{
		for(unsigned i = 0; i < instance->numInputChannels && i < instance->numInputChannelsRegistered; i++)
		{
			buffers[i] = (float *) ioData->mBuffers[i].mData;
			instance->input[i](buffers[i], inNumberFrames);
		}
        
        for(UInt32 frame = 0; frame < inNumberFrames; frame++)
        {
            Float32 sample = 0.0;
            for(unsigned i = 0; i < instance->numInputChannels; i++)
            {
                sample += buffers[i][frame];
            }
            for(unsigned i = 0; i < instance->numInputChannels; i++)
            {
                buffers[i][frame] = sample;
            }

        }
	}
    
    

	
//    Float32 * data = (Float32 *) ioData->mBuffers[0].mData;
//    Float32 * data2 = (Float32 *) ioData->mBuffers[1].mData;
//    Float32 * data3 = (Float32 *) ioData->mBuffers[2].mData;
//    Float32 * data4 = (Float32 *) ioData->mBuffers[3].mData;
//    for(UInt32 frame = 0; frame < inNumberFrames; frame++)
//    {
//        Float32 sample =  data[frame] + data2[frame] + data3[frame] + data4[frame];;
//        data[frame] = data2[frame] = data3[frame] = data4[frame] = sample;
//    }
    
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
    AudioUnit au = aggregateAudioUnit->getInputUnit();
	CheckError(AudioOutputUnitStart(au),
			   "AudioOutputUnitStart failed");
	CheckError(AUGraphStart(this->graph),
			   "AUGraphStart failed");
}

void CAWL::stopPlaying()
{
    AudioUnit au = aggregateAudioUnit->getInputUnit();
	CheckError(AudioOutputUnitStop(au),
			   "AudioOutputUnitStop failed");
	CheckError(AUGraphStop(this->graph),
			   "AUGraphStart failed");
}






