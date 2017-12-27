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
    gainTitle = [self drawLabelTextFieldWithRect:NSMakeRect(35, 320, 35, MAX_TEXTFIELD_HEIGHT)
                                       WithTitle:@"Gain"
                                          toView:self];
    
    gainSlider = [self drawCircularSliderWithRect:NSMakeRect(35, 290, 30, 30)
                                       WithMaxVal:1.0
                                    AndWithMinVal:0.0
                                     atDefaultVal:0.5
                                           toView:self
                                     withSelector:@selector(updateGainLevel:)];
    gainValue = [self drawValueTextFieldWithRect:NSMakeRect(25, 260, 50, MAX_TEXTFIELD_HEIGHT)
                                           toView:self];
}

-(void) setupVolumeUI {
    volumeTitle = [self drawLabelTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-25, 320, 50, MAX_TEXTFIELD_HEIGHT)
                                         WithTitle:@"Volume"
                                            toView:self];
    
    volumeSlider = [self drawCircularSliderWithRect:NSMakeRect(MAX_WIDTH/2-15, 290, 30, 30)
                                         WithMaxVal:1.0
                                      AndWithMinVal:0.0
                                       atDefaultVal:0.5
                                             toView:self
                                       withSelector:@selector(updateVolumeLevel:)];
    volumeValue = [self drawValueTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-25, 260, 50, MAX_TEXTFIELD_HEIGHT)
                                            toView:self];
}

-(void) setupToneUI {
    toneTitle = [self drawLabelTextFieldWithRect:NSMakeRect(175, 320, 40, MAX_TEXTFIELD_HEIGHT)
                                       WithTitle:@"Tone"
                                          toView:self];
    
    toneSlider = [self drawCircularSliderWithRect:NSMakeRect(180, 290, 30, 30)
                                       WithMaxVal:1.0
                                    AndWithMinVal:0.0
                                     atDefaultVal:0.5
                                           toView:self
                                     withSelector:@selector(updateToneLevel:)];
    toneValue = [self drawValueTextFieldWithRect:NSMakeRect(170, 260, 50, MAX_TEXTFIELD_HEIGHT)
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







