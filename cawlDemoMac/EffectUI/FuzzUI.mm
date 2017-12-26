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
    NSSlider *mixLevelSlider;
	
	NSTextField *gainTitle;
	NSTextField *volumeTitle;
	NSTextField *toneTitle;
    NSTextField *mixTitle;
    
    NSTextField *gainValue;
    NSTextField *volumeValue;
    NSTextField *toneValue;
    NSTextField *mixLevelValue;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupGainUI];
    [self setupVolumeUI];
    [self setupToneUI];
    [self setupMixLevelUI];
    return self;
}
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

#pragma mark SETUP_UI

-(void) setupGainUI {
    gainTitle = [self drawLabelTextFieldWithRect:NSMakeRect(20, 320, 40, MAX_TEXTFIELD_HEIGHT)
                                       WithTitle:@"Gain"
                                          toView:self];
    
    gainSlider = [self drawCircularSliderWithRect:NSMakeRect(20, 290, 30, 30)
                                       WithMaxVal:1.0
                                    AndWithMinVal:0.0
                                     atDefaultVal:0.5
                                           toView:self
                                     withSelector:@selector(updateGainLevel:)];
    gainValue = [self drawValueTextFieldWithRect:NSMakeRect(20, 260, 40, MAX_TEXTFIELD_HEIGHT)
                                           toView:self];
}

-(void) setupVolumeUI {
    volumeTitle = [self drawLabelTextFieldWithRect:NSMakeRect(85, 320, 50, MAX_TEXTFIELD_HEIGHT)
                                         WithTitle:@"Volume"
                                            toView:self];
    
    volumeSlider = [self drawCircularSliderWithRect:NSMakeRect(95, 290, 30, 30)
                                         WithMaxVal:1.0
                                      AndWithMinVal:0.0
                                       atDefaultVal:0.5
                                             toView:self
                                       withSelector:@selector(updateVolumeLevel:)];
    volumeValue = [self drawValueTextFieldWithRect:NSMakeRect(90, 260, 40, MAX_TEXTFIELD_HEIGHT)
                                            toView:self];
}

-(void) setupToneUI {
    toneTitle = [self drawLabelTextFieldWithRect:NSMakeRect(160, 320, 40, MAX_TEXTFIELD_HEIGHT)
                                       WithTitle:@"Tone"
                                          toView:self];
    
    toneSlider = [self drawCircularSliderWithRect:NSMakeRect(160, 290, 30, 30)
                                       WithMaxVal:1.0
                                    AndWithMinVal:0.0
                                     atDefaultVal:0.5
                                           toView:self
                                     withSelector:@selector(updateToneLevel:)];
    toneValue = [self drawValueTextFieldWithRect:NSMakeRect(150, 260, 55, MAX_TEXTFIELD_HEIGHT)
                                          toView:self];
}

-(void) setupMixLevelUI {
    
}

#pragma mark IBACTION_FUZZ

-(IBAction) updateGainLevel:(id)sender {
    gainValue.stringValue = [NSString stringWithFormat:@"%.02f", gainSlider.floatValue * 10];
    self.soundTabRef.soundBoard->setFuzzGain(gainSlider.floatValue);
}

-(IBAction) updateVolumeLevel:(id)sender {
    volumeValue.stringValue = [NSString stringWithFormat:@"%.02f", volumeSlider.floatValue * 10];
    //self.soundTabRef.soundBoard->setOverdriveGain(driveSlider.intValue);
}

-(IBAction) updateToneLevel:(id)sender {
    toneValue.stringValue = [NSString stringWithFormat:@"%.02f %%", (toneSlider.floatValue * 100)];
    if(toneSlider.floatValue >= .5) {
        self.soundTabRef.soundBoard->setFuzzToneLevel((toneSlider.floatValue-.5)/.5 * 12.0);
    }
    else {
        self.soundTabRef.soundBoard->setFuzzToneLevel(toneSlider.floatValue/.5 * -12.0);
    }
}

-(IBAction) updateMixLevel:(id)sender {
    
}

@end







