//
//  ReverbUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "ReverbUI.h"

@implementation ReverbUI {
    NSSlider *reverbTimeSlider;
	NSSlider *mixLevelSlider;
	NSSlider *toneLevelSlider; //Treble boost probably a shelving filter or something
	
	
	NSTextField *reverbTimeTitle;
	NSTextField *mixLevelTitle;
	NSTextField *toneLevelTitle;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupReverbTimeUI];
    
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

#pragma mark SETUP_UI
- (void) setupReverbTimeUI {
    reverbTimeSlider = [self drawCircularSliderWithRect:NSMakeRect(90, 320, 30, 30)
                                             WithMaxVal:10
                                          AndWithMinVal:100
                                           atDefaultVal:10
                                                 toView:self
                                           withSelector:@selector(updateReverbTime:)];
}

-(void) setupMixLevelUI {
	
}

-(void) setupToneLevelUI {
	
}

#pragma mark IBACTION_REVERB
- (IBAction)updateReverbTime:(NSSlider *) sender {
    
}

- (IBAction) updateMixLevel:(id)sender {
	
}

- (IBAction) updateToneLevel:(id)sender {
	
}

@end







