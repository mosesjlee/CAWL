//
//  OverdriveUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/22/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "OverdriveUI.h"

@implementation OverdriveUI {
	NSSlider 	*driveSlider;
	NSSlider 	*volumeSlider;
	NSSlider 	*toneKnob;
	
	NSTextField *driveTitle;
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

-(void) setupDriveUI {
	
}

-(void) setupVolumeUI {
	
}

-(void) setupToneUI {
	
}

#pragma mark IBACTION_OVERDRIVE

-(IBAction) updateDriveLevel:(id)sender {
	
}

-(IBAction) updateVolumeLevel:(id)sender {
	
}

-(IBAction) updateToneLevel:(id)sender {
	
}
@end



