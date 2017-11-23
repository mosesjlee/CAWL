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
    [self setupGainUI];
    [self setupVolumeUI];
    [self setupToneUI];
    return self;
}
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

#pragma mark SETUP_UI

-(void) setupGainUI {
    gainTitle = [self drawLabelTextFieldWithRect:NSMakeRect(20, 320, 40, 25)
                                       WithTitle:@"Gain"
                                          toView:self];
    
    gainSlider = [self drawCircularSliderWithRect:NSMakeRect(20, 290, 30, 30)
                                       WithMaxVal:1.0
                                    AndWithMinVal:0.0
                                     atDefaultVal:0.5
                                           toView:self
                                     withSelector:@selector(updateGainLevel:)];
}

-(void) setupVolumeUI {
    volumeTitle = [self drawLabelTextFieldWithRect:NSMakeRect(85, 320, 50, 25)
                                         WithTitle:@"Volume"
                                            toView:self];
    
    volumeSlider = [self drawCircularSliderWithRect:NSMakeRect(95, 290, 30, 30)
                                         WithMaxVal:1.0
                                      AndWithMinVal:0.0
                                       atDefaultVal:0.5
                                             toView:self
                                       withSelector:@selector(updateVolumeLevel:)];
}

-(void) setupToneUI {
    toneTitle = [self drawLabelTextFieldWithRect:NSMakeRect(160, 320, 40, 25)
                                       WithTitle:@"Tone"
                                          toView:self];
    
    toneSlider = [self drawCircularSliderWithRect:NSMakeRect(160, 290, 30, 30)
                                       WithMaxVal:1.0
                                    AndWithMinVal:0.0
                                     atDefaultVal:0.5
                                           toView:self
                                     withSelector:@selector(updateToneLevel:)];
}

#pragma mark IBACTION_FUZZ

-(IBAction) updateGainLevel:(id)sender {
	
}

-(IBAction) updateVolumeLevel:(id)sender {
	
}

-(IBAction) updateToneLevel:(id)sender {
	
}

@end







