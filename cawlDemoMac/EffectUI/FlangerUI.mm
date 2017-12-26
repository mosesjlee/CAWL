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
    NSSlider *mixLevelSlider;
    
    NSTextField *modDepthValue;
    NSTextField *modSpeedValue;
    NSTextField *mixLevelValue;
    
    NSTextField *modDepthTitle;
    NSTextField *modSpeedTitle;
    NSTextField *mixLevelTitle;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupModDepthUI];
    [self setupModSpeedUI];
    [self setupMixLevelUI];
    return self;
}
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

#pragma mark FLANGER_UI_SETUP
- (void)setupModDepthUI {
    modDepthTitle = [self drawLabelTextFieldWithRect:NSMakeRect(5, 320, 80, MAX_TEXTFIELD_HEIGHT)
                                           WithTitle:@"Mod Depth"
                                              toView:self];
    
    modDepthSlider = [self drawCircularSliderWithRect:NSMakeRect(30, 290, 30, 30)
                                           WithMaxVal:10
                                        AndWithMinVal:0
                                         atDefaultVal:5
                                               toView:self
                                         withSelector:@selector(updateModDepth:)];
    
    modDepthValue = [self drawValueTextFieldWithRect:NSMakeRect(20, 260, 55, MAX_TEXTFIELD_HEIGHT)
                                              toView:self];
}

- (void)setupModSpeedUI {
    modSpeedTitle = [self drawLabelTextFieldWithRect:NSMakeRect(75, 320, 80, MAX_TEXTFIELD_HEIGHT)
                                           WithTitle:@"Mod Speed"
                                              toView:self];
    
    modSpeedSlider = [self drawCircularSliderWithRect:NSMakeRect(100, 290, 30, 30)
                                           WithMaxVal:10
                                        AndWithMinVal:0
                                         atDefaultVal:5
                                               toView:self
                                         withSelector:@selector(updateModSpeed:)];
    
    modSpeedValue = [self drawValueTextFieldWithRect:NSMakeRect(85, 260, 55, MAX_TEXTFIELD_HEIGHT)
                                              toView:self];
}

- (void) setupMixLevelUI {
    mixLevelTitle = [self drawLabelTextFieldWithRect:NSMakeRect(145, 320, 70, MAX_TEXTFIELD_HEIGHT)
                                           WithTitle:@"Mix Level"
                                              toView:self];
    
    mixLevelSlider = [self drawCircularSliderWithRect:NSMakeRect(120, 290, 70, 30)
                                           WithMaxVal:1.0
                                        AndWithMinVal:0.0
                                         atDefaultVal:0.5
                                               toView:self
                                         withSelector:@selector(updateMixLevel:)];
    
    mixLevelValue = [self drawValueTextFieldWithRect:NSMakeRect(150, 260, 55, MAX_TEXTFIELD_HEIGHT)
                                              toView:self];
}

#pragma mark FLANGER_ACTIONS
- (IBAction) updateModSpeed:(NSSlider*) sender {
    modSpeedValue.stringValue = [NSString stringWithFormat:@"%f", modSpeedSlider.floatValue];
    self.soundTabRef.soundBoard->setFlangerModulationSpeed(modSpeedSlider.floatValue);
}

- (IBAction) updateModDepth:(NSSlider*) sender {
    modDepthValue.stringValue = [NSString stringWithFormat:@"%f", modDepthSlider.floatValue];
    self.soundTabRef.soundBoard->setFlangerModulationDepth(modSpeedSlider.floatValue);
}

- (IBAction)updateMixLevel:(id)sender {
    mixLevelValue.stringValue = [NSString stringWithFormat:@"%.02f %%", mixLevelSlider.floatValue * 100];
    self.soundTabRef.soundBoard->setFlangerMixLevel(mixLevelSlider.floatValue);
}

@end




