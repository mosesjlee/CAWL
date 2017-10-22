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
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}

- (void)setupLowShelfUI {
    //lowShelfFreqSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(<#CGFloat x#>, <#CGFloat y#>, <#CGFloat w#>, <#CGFloat h#>)];
}

- (void)setupHighShelfUI {
    
}

- (void)setupLowMidUI {
    
}

- (void)setupHighMidUI {
    
}



@end
