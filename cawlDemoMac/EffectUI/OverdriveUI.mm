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
	NSSlider 	*toneKnob;      //Probably a high shelving filter
	
	NSTextField *driveTitle;
	NSTextField *volumeTitle;
	NSTextField *toneTitle;
    
    NSTextField *driveValue;
    NSTextField *volumeValue;
    NSTextField *toneValue;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupDriveUI];
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

-(void) setupDriveUI {
	driveTitle = [self drawLabelTextFieldWithRect:NSMakeRect(20, 320, 40, 25)
                                        WithTitle:@"Drive"
                                           toView:self];
    
    driveSlider = [self drawCircularSliderWithRect:NSMakeRect(20, 290, 30, 30)
                                        WithMaxVal:1.0
                                     AndWithMinVal:0.0
                                      atDefaultVal:0.5
                                            toView:self
                                      withSelector:@selector(updateDriveLevel:)];
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
    
    toneKnob = [self drawCircularSliderWithRect:NSMakeRect(160, 290, 30, 30)
                                     WithMaxVal:1.0
                                  AndWithMinVal:0.0
                                   atDefaultVal:0.5
                                         toView:self
                                   withSelector:@selector(updateToneLevel:)];
}

#pragma mark IBACTION_OVERDRIVE

-(IBAction) updateDriveLevel:(id)sender {
	
}

-(IBAction) updateVolumeLevel:(id)sender {
	
}

-(IBAction) updateToneLevel:(id)sender {
	
}
@end



