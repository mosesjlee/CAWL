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
    
    //Gain Titiles
    NSTextField *lowShelfGainTitle;
    NSTextField *highShelfGainTitle;
    NSTextField *lowMidGainTitle;
    NSTextField *highMidGainTitle;
    
	//Frequency Titles
	NSTextField *lowShelfFreqTitle;
	NSTextField *highShelfFreqTitle;
	NSTextField *lowMidFreqTitle;
	NSTextField *highMidFreqTitle;
	
    //Q Factor levels
    NSTextField *lowMidQFactorLabel;
    NSTextField *highMidQFactorLabel;
    
    //Q Factor Sliders
    NSSlider *lowMidQFactorSlider;
    NSSlider *highMidQFactorSlider;
	
	//Q Factor Titles
	NSTextField *lowMidQFactorTitle;
	NSTextField *highMidQFactorTitle;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupLowShelfUI];
    [self setupHighShelfUI];
    [self setupLowMidUI];
    [self setupHighMidUI];
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

#pragma mark SETUP_UI
- (void)setupLowShelfUI {
    //Frequency Choice
    //Title
    lowShelfFreqLabel = [self drawLabelTextFieldWithRect:NSMakeRect(15, 320, 35, MAX_TEXTFIELD_HEIGHT)
                                               WithTitle:@"Low"
                                                  toView:self];
    
	//Slider
    lowShelfFreqSlider = [self drawCircularSliderWithRect:NSMakeRect(15, 290, 30, 30)
                                               WithMaxVal:200
                                            AndWithMinVal:20
                                             atDefaultVal:80
                                                   toView:self
                                             withSelector:@selector(updateLowShelfCenterFreq:)];
    
    //Value
    lowShelfFreqLabel = [self drawValueTextFieldWithRect:NSMakeRect(5, 260, 60, MAX_TEXTFIELD_HEIGHT)
                                                  toView:self];
    
    //Gain Level
    //Title
    lowShelfGainTitle = [self drawLabelTextFieldWithRect:NSMakeRect(15, 230, 35, MAX_TEXTFIELD_HEIGHT)
                                               WithTitle:@"Gain"
                                                  toView:self];
    
    //Slider
    lowShelfGainSlider = [self drawRegularSliderWithRect:NSMakeRect(50, 170, 70, 30)
                                              WithMaxVal:24
                                           AndWithMinVal:-24
                                            atDefaultVal:0
                                                  toView:self
                                            withSelector:@selector(updateLowShelfGain:)];
    
    //Value
    lowShelfGainLabel = [self drawValueTextFieldWithRect:NSMakeRect(10, 140, 55, MAX_TEXTFIELD_HEIGHT)
                                                  toView:self];
}

- (void)setupHighShelfUI {
    //Frequency Choice
    //Title
    highMidGainTitle = [self drawLabelTextFieldWithRect:NSMakeRect(195, 320, 35, MAX_TEXTFIELD_HEIGHT)
                                              WithTitle:@"High"
                                                 toView:self];
    
    //Slider
    highShelfFreqSlider = [self drawCircularSliderWithRect:NSMakeRect(195, 290, 30, 30)
                                               WithMaxVal:20000
                                            AndWithMinVal:12000
                                             atDefaultVal:15000
                                                   toView:self
                                             withSelector:@selector(updateHighShelfCenterFreq:)];
    
    //Value
    highShelfFreqLabel = [self drawValueTextFieldWithRect:NSMakeRect(185, 260, 60, MAX_TEXTFIELD_HEIGHT)
                                                  toView:self];
    
    //Gain Level
    //Title
    highShelfGainTitle = [self drawLabelTextFieldWithRect:NSMakeRect(200, 230, 35, MAX_TEXTFIELD_HEIGHT)
                                               WithTitle:@"Gain"
                                                  toView:self];
    
    //Slider
    highShelfGainSlider = [self drawRegularSliderWithRect:NSMakeRect(230, 170, 70, 30)
                                              WithMaxVal:24
                                           AndWithMinVal:-24
                                            atDefaultVal:0
                                                  toView:self
                                            withSelector:@selector(updateHighShelfGain:)];
    
    //Value
    highShelfGainLabel = [self drawValueTextFieldWithRect:NSMakeRect(190, 140, 55, MAX_TEXTFIELD_HEIGHT)
                                                  toView:self];
}

- (void)setupLowMidUI {
    //Frequency Choice
    //Title
    lowMidFreqTitle = [self drawLabelTextFieldWithRect:NSMakeRect(65, 320, 60, MAX_TEXTFIELD_HEIGHT)
                                             WithTitle:@"Low Mid"
                                                toView:self];
    
    //Slider
    lowMidFreqSlider = [self drawCircularSliderWithRect:NSMakeRect(80, 290, 30, 30)
                                               WithMaxVal:5000
                                            AndWithMinVal:200
                                             atDefaultVal:1000
                                                   toView:self
                                             withSelector:@selector(updateLowMidCenterFreq:)];
    
    //Value
    lowMidFreqLabel = [self drawValueTextFieldWithRect:NSMakeRect(65, 260, 60, MAX_TEXTFIELD_HEIGHT)
                                                  toView:self];
    
    //Gain Level
    //Title
    lowMidGainTitle = [self drawLabelTextFieldWithRect:NSMakeRect(80, 230, 35, MAX_TEXTFIELD_HEIGHT)
                                               WithTitle:@"Gain"
                                                  toView:self];
    
    //Slider
    lowMidGainSlider = [self drawRegularSliderWithRect:NSMakeRect(115, 170, 70, 30)
                                              WithMaxVal:24
                                           AndWithMinVal:-24
                                            atDefaultVal:0
                                                  toView:self
                                            withSelector:@selector(updateLowMidGain:)];
    
    //Value
    lowMidGainLabel = [self drawValueTextFieldWithRect:NSMakeRect(70, 140, 55, MAX_TEXTFIELD_HEIGHT)
                                                toView:self];
    
    //Q Factor
    //Title
    lowMidQFactorTitle = [self drawLabelTextFieldWithRect:NSMakeRect(65, 110, 65, MAX_TEXTFIELD_HEIGHT)
                                                WithTitle:@"Q Factor"
                                                   toView:self];
    
    //Slider
    //lowMidQFactorSlider
    lowMidQFactorSlider = [self drawCircularSliderWithRect:NSMakeRect(75, 80, 30, 30)
                                                WithMaxVal:10
                                             AndWithMinVal:0.1
                                              atDefaultVal:1
                                                    toView:self
                                              withSelector:@selector(updateLowMidQFactor:)];
    
    //Value
    lowMidQFactorLabel = [self drawValueTextFieldWithRect:NSMakeRect(70, 50, 40, MAX_TEXTFIELD_HEIGHT)
                                                   toView:self];
}

- (void)setupHighMidUI {
    //Frequency Choice
    //Title
    highMidFreqTitle = [self drawLabelTextFieldWithRect:NSMakeRect(125, 320, 60, MAX_TEXTFIELD_HEIGHT)
                                              WithTitle:@"High Mid"
                                                 toView:self];
    
    //Slider
    highMidFreqSlider = [self drawCircularSliderWithRect:NSMakeRect(135, 290, 30, 30)
                                               WithMaxVal:12000
                                            AndWithMinVal:5000
                                             atDefaultVal:8000
                                                   toView:self
                                             withSelector:@selector(updateHighMidCenterFreq:)];
    
    //Value
    highMidFreqLabel = [self drawValueTextFieldWithRect:NSMakeRect(125, 260, 60, MAX_TEXTFIELD_HEIGHT)
                                                  toView:self];
    
    //Gain Level
    //Title
    highMidGainTitle = [self drawLabelTextFieldWithRect:NSMakeRect(140, 230, 35, MAX_TEXTFIELD_HEIGHT)
                                               WithTitle:@"Gain"
                                                  toView:self];
    
    //Slider
    highMidGainSlider = [self drawRegularSliderWithRect:NSMakeRect(175, 170, 70, 30)
                                              WithMaxVal:24
                                           AndWithMinVal:-24
                                            atDefaultVal:0
                                                  toView:self
                                            withSelector:@selector(updateHighMidGain:)];
    
    //Value
    highMidGainLabel = [self drawValueTextFieldWithRect:NSMakeRect(130, 140, 55, MAX_TEXTFIELD_HEIGHT)
                                                  toView:self];
    
    //Q Factor
    //Title
    highMidQFactorTitle = [self drawLabelTextFieldWithRect:NSMakeRect(125, 110, 65, MAX_TEXTFIELD_HEIGHT)
                                                 WithTitle:@"Q Factor"
                                                    toView:self];
    
    //Slider
    //highMidQFactorSlider
    highMidQFactorSlider = [self drawCircularSliderWithRect:NSMakeRect(140, 80, 30, 30)
                                                WithMaxVal:10
                                             AndWithMinVal:0.1
                                              atDefaultVal:1
                                                    toView:self
                                              withSelector:@selector(updateHighMidQFactor:)];
    
    //Value
    highMidQFactorLabel = [self drawValueTextFieldWithRect:NSMakeRect(135, 50, 40, MAX_TEXTFIELD_HEIGHT)
                                                    toView:self];
}

#pragma mark IBActions

- (void) updateLowShelfGain:(id)sender {
	lowShelfGainLabel.stringValue = [NSString stringWithFormat:@"%.01f dB", lowShelfGainSlider.floatValue];
    self.soundTabRef.soundBoard->setEqLowShelfGain(lowShelfGainSlider.floatValue);
}

- (void) updateHighShelfGain:(id)sender {
    highShelfGainLabel.stringValue = [NSString stringWithFormat:@"%.01f dB", highShelfGainSlider.floatValue];
    self.soundTabRef.soundBoard->setEqHighShelfGain(highShelfGainSlider.floatValue);
}

- (void) updateLowMidGain:(id)sender {
    lowMidGainLabel.stringValue = [NSString stringWithFormat:@"%.01f dB", lowMidGainSlider.floatValue];
    self.soundTabRef.soundBoard->setEqLowMidGain(lowMidGainSlider.floatValue);
}

- (void) updateHighMidGain:(id)sender {
	highMidGainLabel.stringValue = [NSString stringWithFormat:@"%.01f dB", highMidGainSlider.floatValue];
    self.soundTabRef.soundBoard->setEqHighMidGain(highMidGainSlider.floatValue);
}

- (void) updateLowShelfCenterFreq:(id)sender {
    lowShelfFreqLabel.stringValue = [NSString stringWithFormat:@"%d Hz", lowShelfFreqSlider.intValue];
    self.soundTabRef.soundBoard->setEqLowShelfCenterFreq(lowShelfFreqSlider.intValue);
}

- (void) updateHighShelfCenterFreq:(id)sender {
    highShelfFreqLabel.stringValue = [NSString stringWithFormat:@"%.01f KHz",highShelfFreqSlider.floatValue/1000];
    self.soundTabRef.soundBoard->setEqHighShelfCenterFreq(highShelfFreqSlider.intValue);
}

- (void) updateLowMidCenterFreq:(id)sender {
	lowMidFreqLabel.stringValue = [NSString stringWithFormat:@"%d Hz", lowMidFreqSlider.intValue];
    self.soundTabRef.soundBoard->setEqLowMidCenterFreq(lowMidFreqSlider.intValue);
}

- (void) updateHighMidCenterFreq:(id)sender {
	highMidFreqLabel.stringValue = [NSString stringWithFormat:@"%.01f KHz", highMidFreqSlider.floatValue/1000];
    self.soundTabRef.soundBoard->setEqHighMidCenterFreq(highMidFreqSlider.intValue);
}

- (void) updateLowMidQFactor:(id)sender {
    lowMidQFactorLabel.stringValue = [NSString stringWithFormat:@"%.02f", lowMidQFactorSlider.floatValue];
    self.soundTabRef.soundBoard->setEqLowQFactor(lowMidQFactorSlider.floatValue);
}

- (void) updateHighMidQFactor:(id)sender {
    highMidQFactorLabel.stringValue = [NSString stringWithFormat:@"%.02f", highMidQFactorSlider.floatValue];
    self.soundTabRef.soundBoard->setEqHighQFactor(highMidQFactorSlider.floatValue);
}

@end
