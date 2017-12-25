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
    
    driveSlider = [self drawCircularSliderWithRect:NSMakeRect(25, 290, 30, 30)
                                        WithMaxVal:1.0
                                     AndWithMinVal:0.0
                                      atDefaultVal:0.5
                                            toView:self
                                      withSelector:@selector(updateDriveLevel:)];
    driveValue = [self drawValueTextFieldWithRect:NSMakeRect(20, 260, 40, 25)
                                           toView:self];
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
    
    volumeValue = [self drawValueTextFieldWithRect:NSMakeRect(90, 260, 40, 25)
                                            toView:self];
}

-(void) setupToneUI {
    toneTitle = [self drawLabelTextFieldWithRect:NSMakeRect(155, 320, 40, 25)
                                       WithTitle:@"Tone"
                                          toView:self];
    
    toneKnob = [self drawCircularSliderWithRect:NSMakeRect(160, 290, 30, 30)
                                     WithMaxVal:1.0
                                  AndWithMinVal:0.0
                                   atDefaultVal:0.5
                                         toView:self
                                   withSelector:@selector(updateToneLevel:)];
    
    toneValue = [self drawValueTextFieldWithRect:NSMakeRect(150, 260, 55, 25)
                                          toView:self];
}

#pragma mark IBACTION_OVERDRIVE

-(IBAction) updateDriveLevel:(id)sender {
    driveValue.stringValue = [NSString stringWithFormat:@"%.02f", driveSlider.floatValue * 10];
    self.soundTabRef.soundBoard->setOverdriveGain(driveSlider.floatValue);
}

-(IBAction) updateVolumeLevel:(id)sender {
    volumeValue.stringValue = [NSString stringWithFormat:@"%.02f", volumeSlider.floatValue * 10];
    //self.soundTabRef.soundBoard->setOverdriveGain(driveSlider.intValue);
}

-(IBAction) updateToneLevel:(id)sender {
    toneValue.stringValue = [NSString stringWithFormat:@"%.02f %%", (toneKnob.floatValue * 100)];
    if(toneKnob.floatValue >= .5) {
        self.soundTabRef.soundBoard->setOverdriveToneLevel((toneKnob.floatValue-.5)/.5 * 12.0);
    }
    else {
        self.soundTabRef.soundBoard->setOverdriveToneLevel(toneKnob.floatValue/.5 * -12.0);
    }
}
@end



