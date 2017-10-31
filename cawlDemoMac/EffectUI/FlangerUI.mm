//
//  FlangerUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/22/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "FlangerUI.h"

@implementation FlangerUI {
    NSSlider *modDepthSlider;
    NSSlider *modSpeedSlider;
    
    NSTextField *modDepthLabel;
    NSTextField *modSpeedLabel;
    
    NSTextField *modDepthTitle;
    NSTextField *modSpeedTitle;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupModDepthUI];
    [self setupModSpeedUI];
    return self;
}
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

- (void)setupModDepthUI {
    modDepthTitle = [self drawLabelTextFieldWithRect:NSMakeRect(15, 320, 70, 30)
                                           WithTitle:@"Mod Depth"];
    [self addSubview:modDepthTitle];
    
    modDepthSlider = [self drawCircularSliderWithRect:NSMakeRect(15, 220, 30, 30)
                                           WithMaxVal:0
                                        AndWithMinVal:10];
    [self addSubview:modDepthSlider];
    
    modDepthLabel = [self drawValueTextFieldWithRect:NSMakeRect(15, 260, 30, 20)];
    [self addSubview:modDepthLabel];
}

- (void)setupModSpeedUI {
    modSpeedTitle = [self drawLabelTextFieldWithRect:NSMakeRect(100, 320, 70, 30)
                                           WithTitle:@"Mod Speed"];
    [self addSubview:modSpeedTitle];
    
    modSpeedSlider = [self drawCircularSliderWithRect:NSMakeRect(100, 220, 30, 30)
                                           WithMaxVal:0
                                        AndWithMinVal:10];
    [self addSubview:modSpeedSlider];
    
    modSpeedLabel = [self drawValueTextFieldWithRect:NSMakeRect(100, 260, 30, 20)];
    [self addSubview:modSpeedLabel];
}

- (void) updateModSpeed:(id) sender {
    
}

- (void) updateModDepth:(id) sender {
    
}


@end




