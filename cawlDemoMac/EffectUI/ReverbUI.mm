//
//  ReverbUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "ReverbUI.h"

@implementation ReverbUI {
    NSSlider * reverbTimeSlider;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupReverbTimeUI];
    [self drawBorder:frameRect];
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}

- (void)setupReverbTimeUI {
    reverbTimeSlider = [self drawCircularSliderWithRect:NSMakeRect(90, 320, 30, 30)
                                             WithMaxVal:10
                                          AndWithMinVal:100];
    [self addSubview:reverbTimeSlider];
}
@end
