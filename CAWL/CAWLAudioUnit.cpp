//
//  CAWLAudioUnit.cpp
//  CAWL
//
//  Created by Moses Lee on 9/14/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLAudioUnit.hpp"
#include "CAWLUtilities.hpp"

CAWLAudioUnit::CAWLAudioUnit()
{
    setupAudioUnitIO();
    setDefaultInputAudioUnit();
}

CAWLAudioUnit::~CAWLAudioUnit()
{
	
}

OSStatus CAWLAudioUnit::setDefaultInputAudioUnit()
{
    OSStatus theStatus = noErr;
    AudioUnitScope outputBus = 0;
    AudioUnitScope inputBus = 1;
    
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
    
    CheckError((theStatus = AudioObjectGetPropertyData(kAudioObjectSystemObject,
                                                       &defaultDeviceProperty,
                                                       0,
                                                       NULL,
                                                       &propertySize,
                                                       &defaultDevice)),
               "Couldn't get default input device");
    
    CheckError((theStatus = AudioUnitSetProperty(inputUnit,
                                                 kAudioOutputUnitProperty_CurrentDevice,
                                                 kAudioUnitScope_Global,
                                                 outputBus,
                                                 &defaultDevice,
                                                 sizeof(defaultDevice))),
               "Couldn't set default device on I/O unit");
    
    //Get the ASBD from Input AUHAL
    propertySize = sizeof(AudioStreamBasicDescription);
    CheckError((theStatus = AudioUnitGetProperty(inputUnit,
                                                 kAudioUnitProperty_StreamFormat,
                                                 kAudioUnitScope_Output,
                                                 inputBus,
                                                 &aggregateASBD,
                                                 &propertySize)),
               "Couldn't get ASBD from Input unit");
    
    //Adopt Hardware input sample
    AudioStreamBasicDescription deviceFormat;
    CheckError(AudioUnitGetProperty(inputUnit,
                                    kAudioUnitProperty_StreamFormat,
                                    kAudioUnitScope_Input,
                                    inputBus,
                                    &deviceFormat,
                                    &propertySize),
               "Couldn't get ASBD from input unit");
    
    aggregateASBD.mSampleRate       = deviceFormat.mSampleRate;
    aggregateASBD.mChannelsPerFrame = deviceFormat.mChannelsPerFrame;
    
    propertySize = sizeof(AudioStreamBasicDescription);
    CheckError((theStatus = AudioUnitSetProperty(inputUnit,
                                                 kAudioUnitProperty_StreamFormat,
                                                 kAudioUnitScope_Output,
                                                 inputBus,
                                                 &aggregateASBD,
                                                 propertySize)),
               "Couldn't set ASBD on input unit");
    
	return theStatus;
}


OSStatus CAWLAudioUnit::setupAudioUnitIO()
{
	OSStatus theStatus = noErr;
    /***********************************************
     This section enables the input and
     disables the output for this AudioUnit
     that we designated as the input
     ***********************************************/
    UInt32 disableFlag = 0;
    UInt32 enableFlag = 1;
    AudioUnitScope outputBus = 0;
    AudioUnitScope inputBus = 1;

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
    
    CheckError((theStatus = AudioUnitSetProperty(inputUnit,
                                                 kAudioOutputUnitProperty_EnableIO,
                                                 kAudioUnitScope_Input,
                                                 inputBus,
                                                 &enableFlag,
                                                 sizeof(enableFlag))),
               "Couldn't enable input on I/O unit");
    
    CheckError((theStatus = AudioUnitSetProperty(inputUnit,
                                                 kAudioOutputUnitProperty_EnableIO,
                                                 kAudioUnitScope_Output,
                                                 outputBus,
                                                 &disableFlag,
                                                 sizeof(disableFlag))),
               "Couldn't disable output on I/O unit");
	return theStatus;
}

