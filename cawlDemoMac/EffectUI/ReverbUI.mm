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
    
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

- (void)setupReverbTimeUI {
    reverbTimeSlider = [self drawCircularSliderWithRect:NSMakeRect(90, 320, 30, 30)
                                             WithMaxVal:10
                                          AndWithMinVal:100
                                           atDefaultVal:10
                                                 toView:self
                                           withSelector:@selector(updateReverbTime:)];
}

- (IBAction)updateReverbTime:(NSSlider *) sender {
    
}
@end
