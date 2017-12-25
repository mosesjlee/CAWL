//
//  WahUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "WahUI.h"

@implementation WahUI {
    //Sliders
    NSSlider *mixLevelSlider;
    NSSlider *wahDepthSlider;
    NSSlider *wahRateSlider;
    NSSlider *centerFreqSlider;
    
    //Labels
    NSTextField *mixLevelLabel;
    NSTextField *wahDepthLabel;
    NSTextField *wahRateLabel;
    NSTextField *centerFreqLabel;
    
    //Value Fields
    NSTextField *mixLevelValueField;
    NSTextField *wahDepthValueField;
    NSTextField *wahRateValueField;
    NSTextField *centerFreqValueField;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupMixLevelUI];
    [self setupWahRateUI];
    [self setupWahDepthUI];
    [self setupCenterFreqUI];
    return self;
}
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}
#pragma mark SETUP_UI
-(void) setupMixLevelUI {
    mixLevelLabel = [self drawLabelTextFieldWithRect:NSMakeRect(40, 320, 30, 25)
                                           WithTitle:@"Mix"
                                              toView:self];
    
	mixLevelSlider = [self drawCircularSliderWithRect:NSMakeRect(40, 295, 30, 30)
                                           WithMaxVal:1.0
                                        AndWithMinVal:0
                                         atDefaultVal:1.0
                                               toView:self
                        withSelector:@selector(updateMixLevel:)];
    
    mixLevelValueField = [self drawValueTextFieldWithRect:NSMakeRect(30, 265, 55, 25)
                                                   toView:self];
    
}

-(void) setupWahDepthUI {
    wahDepthLabel = [self drawLabelTextFieldWithRect:NSMakeRect(140, 320, 45, 25)
                                           WithTitle:@"Depth"
                                              toView:self];
    
    wahDepthSlider = [self drawCircularSliderWithRect:NSMakeRect(145, 295, 30, 30)
                                           WithMaxVal:1.0
                                        AndWithMinVal:0
                                         atDefaultVal:1.0
                                               toView:self
                                         withSelector:@selector(updateWahDepth:)];
    
   wahDepthValueField = [self drawValueTextFieldWithRect:NSMakeRect(135, 265, 55, 25)
                                                  toView:self];
}

-(void) setupWahRateUI {
   wahRateLabel = [self drawLabelTextFieldWithRect:NSMakeRect(40, 220, 35, 25)
                           WithTitle:@"Rate"
                              toView:self];
    
    wahRateSlider = [self drawCircularSliderWithRect:NSMakeRect(40, 195, 30, 30)
                                          WithMaxVal:1.0
                                       AndWithMinVal:0
                                        atDefaultVal:1.0
                                              toView:self
                                        withSelector:@selector(updateWahRate:)];
    
    wahRateValueField = [self drawValueTextFieldWithRect:NSMakeRect(30, 165, 55, 25)
                                                  toView:self];
}

-(void) setupCenterFreqUI {
    centerFreqLabel = [self drawLabelTextFieldWithRect:NSMakeRect(130, 220, 80, 25)
                                             WithTitle:@"Center Freq"
                                                toView:self];
    
    centerFreqSlider = [self drawCircularSliderWithRect:NSMakeRect(145, 195, 30, 30)
                                             WithMaxVal:1400.0
                                          AndWithMinVal:800
                                           atDefaultVal:800
                                                 toView:self
                                           withSelector:@selector(updateWahCenterFreq:)];
    
    centerFreqValueField = [self drawValueTextFieldWithRect:NSMakeRect(135, 165, 55, 25)
                                                     toView:self];
}
#pragma mark IBACTION_WAH

-(IBAction) updateMixLevel:(id)sender {
    mixLevelValueField.stringValue = [NSString stringWithFormat:@"%.02f %%", mixLevelSlider.floatValue * 100];
    self.soundTabRef.soundBoard->setWahMixLevel(mixLevelSlider.floatValue);
}

-(IBAction) updateWahDepth:(id)sender {
	wahDepthValueField.stringValue = [NSString stringWithFormat:@"%.02f %%", wahDepthSlider.floatValue * 100];
    self.soundTabRef.soundBoard->setWahModulationDepth(wahDepthLabel.floatValue);
}

-(IBAction) updateWahRate:(id)sender {
    wahRateValueField.stringValue = [NSString stringWithFormat:@"%.02f %%", wahRateSlider.floatValue * 100];
    self.soundTabRef.soundBoard->setWahModulationRate(wahRateSlider.floatValue);
}

-(IBAction) updateWahCenterFreq:(id)sender {
    centerFreqValueField.stringValue = [NSString stringWithFormat:@"%d Hz", centerFreqSlider.intValue];
    self.soundTabRef.soundBoard->setWahCenterFreq(centerFreqSlider.intValue);
}

@end




