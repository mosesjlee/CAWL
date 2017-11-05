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
                                           WithTitle:@"Mod Depth"
                                              toView:self];
    
    modDepthSlider = [self drawCircularSliderWithRect:NSMakeRect(15, 220, 30, 30)
                                           WithMaxVal:10
                                        AndWithMinVal:0
                                         atDefaultVal:5
                                               toView:self
                                         withSelector:@selector(updateModDepth:)];
    
    modDepthLabel = [self drawValueTextFieldWithRect:NSMakeRect(15, 260, 30, 20)
                                              toView:self];
}

- (void)setupModSpeedUI {
    modSpeedTitle = [self drawLabelTextFieldWithRect:NSMakeRect(100, 320, 70, 30)
                                           WithTitle:@"Mod Speed"
                                              toView:self];
    
    modSpeedSlider = [self drawCircularSliderWithRect:NSMakeRect(100, 220, 30, 30)
                                           WithMaxVal:10
                                        AndWithMinVal:0
                                         atDefaultVal:5
                                               toView:self
                                         withSelector:@selector(updateModSpeed:)];
    
    modSpeedLabel = [self drawValueTextFieldWithRect:NSMakeRect(100, 260, 30, 20)
                                              toView:self];
}

- (IBAction) updateModSpeed:(NSSlider*) sender {
    modSpeedLabel.stringValue = [NSString stringWithFormat:@"%f", modSpeedSlider.floatValue];
    //self.soundTabRef.soundBoard->setFlanger(modSpeedSlider.floatValue);
}

- (IBAction) updateModDepth:(NSSlider*) sender {
    modDepthLabel.stringValue = [NSString stringWithFormat:@"%f", modDepthSlider.floatValue];
    //self.soundTabRef.soundBoard->setFlanger(modSpeedSlider.floatValue);
}


@end




