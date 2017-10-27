//
//  EqualizerUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "EqualizerUI.h"

@implementation EqualizerUI {
    //Frequency Sliders
    NSSlider *lowShelfFreqSlider;
    NSSlider *highShelfFreqSlider;
    NSSlider *lowMidFreqSlider;
    NSSlider *highMidFreqSlider;
    
    //Gain Sliders
    NSSlider *lowShelfGainSlider;
    NSSlider *highShelfGainSlider;
    NSSlider *lowMidGainSlider;
    NSSlider *highMidGainSlider;
    
    //Frequency labels
    NSTextField *lowShelfFreqLabel;
    NSTextField *highShelfFreqLabel;
    NSTextField *lowMidFreqLabel;
    NSTextField *highMidFreqLabel;
    
    //Gain labels
    NSTextField *lowShelfGainLabel;
    NSTextField *highShelfGainLabel;
    NSTextField *lowMidGainLabel;
    NSTextField *highMidGainLabel;
	
	//Frequency Titles
	NSTextField *lowShelfFreqTitle;
	NSTextField *highShelfFreqTitle;
	NSTextField *lowMidFreqTitle;
	NSTextField *highMidFreqTitle;
	
    //Q Factor levels
    NSTextField *lowMidQFactorLabel;
    NSTextField *highMidQFactorLabel;
	
	//Q Factor Titles
	NSTextField *lowMidQFactorTitle;
	NSTextField *highMidQFactorTitle;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupLowShelfUI];
    
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

#pragma mark SETUP_UI
- (void)setupLowShelfUI {
	//Slider
    lowShelfFreqSlider = [self drawCircularSliderWithRect:NSMakeRect(5, 320, 30, 30)
                                               WithMaxVal:10
                                            AndWithMinVal:200];
	[lowMidFreqSlider setAction:@selector(updateLowShelfGain:)];
    [self addSubview:lowShelfFreqSlider];
	
	//Title
	
}

- (void)setupHighShelfUI {
    
}

- (void)setupLowMidUI {
    
}

- (void)setupHighMidUI {
    
}

#pragma mark IBActions

- (void) updateLowShelfGain:(id)sender {
	
}

- (void) updateHighShelfGain:(id)sender {
	
}

- (void) updateLowMidGain:(id)sender {
	
}

- (void) updateHighMidGain:(id)sender {
	
}

- (void) updateLowShelfCenterFreq:(id)sender {
	
}

- (void) updateHighShelfCenterFreq:(id)sender {
	
}

- (void) updateLowMidCenterFreq:(id)sender {
	
}

- (void) updateHighMidCenterFreq:(id)sender {
	
}

- (void) updateLowMidQFactor:(id)sender {
	
}

- (void) updateHighMidQFactor:(id)sender {
	
}

@end
