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
    
    //Q Factor levels
    NSTextField *lowMidQFactorLabel;
    NSTextField *highMidQFactorLabel;
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

- (void)setupLowShelfUI {
    lowShelfFreqSlider = [self drawCircularSliderWithRect:NSMakeRect(90, 320, 30, 30)
                                               WithMaxVal:10
                                            AndWithMinVal:100];
    [self addSubview:lowShelfFreqSlider];
}

- (void)setupHighShelfUI {
    
}

- (void)setupLowMidUI {
    
}

- (void)setupHighMidUI {
    
}



@end
