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
    
    NSTextField *reverbTimeValueLabel;
    NSTextField *mixLevelValueLabel;
    NSTextField *toneLevelValueLabel;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupReverbTimeUI];
    [self setupMixLevelUI];
    [self setupToneLevelUI];
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

#pragma mark SETUP_UI
- (void) setupReverbTimeUI {
    reverbTimeTitle = [self drawLabelTextFieldWithRect:NSMakeRect(10, 320, 35, 30)
                                             WithTitle:@"Time"
                                                toView:self];
    
    reverbTimeSlider = [self drawCircularSliderWithRect:NSMakeRect(10, 290, 30, 30)
                                             WithMaxVal:10
                                          AndWithMinVal:100
                                           atDefaultVal:10
                                                 toView:self
                                           withSelector:@selector(updateReverbTime:)];
    
    reverbTimeValueLabel = [self drawValueTextFieldWithRect:NSMakeRect(10, 260, 30, 30)
                                                     toView:self];
}

-(void) setupMixLevelUI {
    mixLevelTitle = [self drawLabelTextFieldWithRect:NSMakeRect(60, 320, 30, 30)
                                           WithTitle:@"Mix"
                                              toView:self];
    
    mixLevelSlider = [self drawCircularSliderWithRect:NSMakeRect(60, 290, 30, 30)
                                           WithMaxVal:1.0
                                        AndWithMinVal:0.0
                                         atDefaultVal:0.5
                                               toView:self
                                         withSelector:@selector(updateMixLevel:)];
    
    mixLevelValueLabel = [self drawValueTextFieldWithRect:NSMakeRect(60, 260, 30, 30)
                                                   toView:self];
}

-(void) setupToneLevelUI {
	toneLevelTitle = [self drawLabelTextFieldWithRect:NSMakeRect(110, 320, 30, 30)
                                            WithTitle:@"Tone"
                                               toView:self];
    
    toneLevelSlider = [self drawCircularSliderWithRect:NSMakeRect(110, 290, 30, 30)
                                            WithMaxVal:1.0
                                         AndWithMinVal:0.0
                                          atDefaultVal:0.0
                                                toView:self
                                          withSelector:@selector(updateToneLevel:)];
    
    toneLevelValueLabel = [self drawValueTextFieldWithRect:NSMakeRect(110, 260, 30, 30)
                                                    toView:self];
}

#pragma mark IBACTION_REVERB
- (IBAction)updateReverbTime:(NSSlider *) sender {
    
}

- (IBAction) updateMixLevel:(id)sender {
	
}

- (IBAction) updateToneLevel:(id)sender {
	
}

@end







