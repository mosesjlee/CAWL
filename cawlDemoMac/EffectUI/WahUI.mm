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
    mixLevelLabel = [self drawLabelTextFieldWithRect:NSMakeRect(20, 320, 30, 25)
                                           WithTitle:@"Mix"
                                              toView:self];
    
	mixLevelSlider = [self drawCircularSliderWithRect:NSMakeRect(20, 295, 30, 30)
                                           WithMaxVal:1.0
                                        AndWithMinVal:0
                                         atDefaultVal:1.0
                                               toView:self
                        withSelector:@selector(updateMixLevel:)];
    
    mixLevelValueField = [self drawValueTextFieldWithRect:NSMakeRect(20, 265, 30, 25)
                                                   toView:self];
    
}

-(void) setupWahDepthUI {
    wahDepthLabel = [self drawLabelTextFieldWithRect:NSMakeRect(65, 320, 45, 25)
                                           WithTitle:@"Depth"
                                              toView:self];
    
    wahDepthSlider = [self drawCircularSliderWithRect:NSMakeRect(70, 295, 30, 30)
                                           WithMaxVal:1.0
                                        AndWithMinVal:0
                                         atDefaultVal:1.0
                                               toView:self
                                         withSelector:@selector(updateWahDepth:)];
    
   wahDepthValueField = [self drawValueTextFieldWithRect:NSMakeRect(70, 265, 30, 25)
                                                  toView:self];
}

-(void) setupWahRateUI {
   wahRateLabel = [self drawLabelTextFieldWithRect:NSMakeRect(120, 320, 35, 25)
                           WithTitle:@"Rate"
                              toView:self];
    
    wahRateSlider = [self drawCircularSliderWithRect:NSMakeRect(120, 295, 30, 30)
                                          WithMaxVal:1.0
                                       AndWithMinVal:0
                                        atDefaultVal:1.0
                                              toView:self
                                        withSelector:@selector(updateWahRate:)];
    
    wahRateValueField = [self drawValueTextFieldWithRect:NSMakeRect(120, 265, 30, 25)
                                                  toView:self];
}

-(void) setupCenterFreqUI {
   centerFreqLabel =  [self drawLabelTextFieldWithRect:NSMakeRect(170, 320, 35, 25)
                                             WithTitle:@"Freq"
                                                toView:self];
    
    centerFreqSlider = [self drawCircularSliderWithRect:NSMakeRect(170, 295, 30, 30)
                                             WithMaxVal:1.0
                                          AndWithMinVal:0
                                           atDefaultVal:1.0
                                                 toView:self
                                           withSelector:@selector(updateWahCenterFreq:)];
    
    centerFreqValueField = [self drawValueTextFieldWithRect:NSMakeRect(170, 265, 30, 25)
                                                     toView:self];
}
#pragma mark IBACTION_WAH

-(IBAction) updateMixLevel:(id)sender {
    mixLevelValueField.stringValue = [NSString stringWithFormat:@"%f", mixLevelSlider.floatValue];
    self.soundTabRef.soundBoard->setWahMixLevel(mixLevelSlider.floatValue);
}

-(IBAction) updateWahDepth:(id)sender {
	wahDepthValueField.stringValue = [NSString stringWithFormat:@"%f", wahDepthSlider.floatValue];
    self.soundTabRef.soundBoard->setWahModulationDepth(wahDepthLabel.floatValue);
}

-(IBAction) updateWahRate:(id)sender {
    wahRateValueField.stringValue = [NSString stringWithFormat:@"%f", wahRateSlider.floatValue];
    self.soundTabRef.soundBoard->setWahModulationRate(wahRateSlider.floatValue);
}

-(IBAction) updateWahCenterFreq:(id)sender {
    centerFreqValueField.stringValue = [NSString stringWithFormat:@"%f", centerFreqSlider.floatValue];
    self.soundTabRef.soundBoard->setWahCenterFreq(centerFreqSlider.floatValue);
}

@end




