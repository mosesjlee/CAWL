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
    reverbTimeTitle = [self drawLabelTextFieldWithRect:NSMakeRect(25, 310, 40, MAX_TEXTFIELD_HEIGHT)
                                             WithTitle:@"Time"
                                                toView:self];
    
    reverbTimeSlider = [self drawCircularSliderWithRect:NSMakeRect(30, 290, 30, 30)
                                             WithMaxVal:100
                                          AndWithMinVal:10
                                           atDefaultVal:10
                                                 toView:self
                                           withSelector:@selector(updateReverbTime:)];
    
    reverbTimeValueLabel = [self drawValueTextFieldWithRect:NSMakeRect(20, 260, 60, MAX_TEXTFIELD_HEIGHT)
                                                     toView:self];
}

-(void) setupMixLevelUI {
    mixLevelTitle = [self drawLabelTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-30, 310, 60, MAX_TEXTFIELD_HEIGHT)
                                           WithTitle:@"Mix"
                                              toView:self];
    
    mixLevelSlider = [self drawCircularSliderWithRect:NSMakeRect(MAX_WIDTH/2-15, 290, 30, 30)
                                           WithMaxVal:1.0
                                        AndWithMinVal:0.0
                                         atDefaultVal:0.5
                                               toView:self
                                         withSelector:@selector(updateMixLevel:)];
    
    mixLevelValueLabel = [self drawValueTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-30, 260, 60, MAX_TEXTFIELD_HEIGHT)
                                                   toView:self];
}

-(void) setupToneLevelUI {
	toneLevelTitle = [self drawLabelTextFieldWithRect:NSMakeRect(175, 310, 40, MAX_TEXTFIELD_HEIGHT)
                                            WithTitle:@"Tone"
                                               toView:self];
    
    toneLevelSlider = [self drawCircularSliderWithRect:NSMakeRect(180, 290, 30, 30)
                                            WithMaxVal:1.0
                                         AndWithMinVal:0.0
                                          atDefaultVal:0.0
                                                toView:self
                                          withSelector:@selector(updateToneLevel:)];
    
    toneLevelValueLabel = [self drawValueTextFieldWithRect:NSMakeRect(170, 260, 60, MAX_TEXTFIELD_HEIGHT)
                                                    toView:self];
}

#pragma mark IBACTION_REVERB
- (IBAction)updateReverbTime:(id *) sender {
    reverbTimeValueLabel.stringValue = [NSString stringWithFormat:@"%d ms", reverbTimeSlider.intValue];
    self.soundTabRef.soundBoard->setReverbTime(reverbTimeSlider.intValue);
}

- (IBAction) updateMixLevel:(id)sender {
	mixLevelValueLabel.stringValue = [NSString stringWithFormat:@"%.02f %%", (mixLevelSlider.floatValue * 100)];
    self.soundTabRef.soundBoard->setReverbMixLevel(mixLevelSlider.floatValue);
}

- (IBAction) updateToneLevel:(id)sender {
    toneLevelValueLabel.stringValue = [NSString stringWithFormat:@"%.02f %%", (toneLevelSlider.floatValue * 100)];
    if(toneLevelSlider.floatValue >= .5) {
        self.soundTabRef.soundBoard->setReverbTone((toneLevelSlider.floatValue-.5)/.5 * 12.0);
        NSLog(@"REVERB TONE %f", (toneLevelSlider.floatValue-.5)/.5 * 12.0);
    }
    else {
        self.soundTabRef.soundBoard->setReverbTone(toneLevelSlider.floatValue/.5 * -12.0);
        NSLog(@"REVERB TONE %f", (.5-toneLevelSlider.floatValue)/.5 * -12.0);
    }
}

@end







