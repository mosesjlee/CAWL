//
//  FuzzUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/22/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "FuzzUI.h"

@implementation FuzzUI {
	NSSlider *gainSlider;
	NSSlider *volumeSlider;
	NSSlider *toneSlider;	//For treble controls
	
	NSTextField *gainTitle;
	NSTextField *volumeTitle;
	NSTextField *toneTitle;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    
    return self;
}
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

#pragma mark SETUP_UI

-(void) setupGainUI {
	
}

-(void) setupVolumeUI {
	
}

-(void) setupToneUI {
	
}

#pragma mark IBACTION_FUZZ

-(IBAction) updateGainLevel:(id)sender {
	
}

-(IBAction) updateVolumeLevel:(id)sender {
	
}

-(IBAction) updateToneLevel:(id)sender {
	
}

@end







