//
//  CAWLUtilities.cpp
//  CAWL
//
//  Created by Moses Lee on 9/14/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLUtilities.hpp"

/**
 This function is copied from the book Learning CoreAudio
 Authors: Chris Adamson, Kevin Avila
 **/
void CheckError(OSStatus error, const char * operation)
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
