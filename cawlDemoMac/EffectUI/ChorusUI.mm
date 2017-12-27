//
//  ChorusUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "ChorusUI.h"

@implementation ChorusUI {
	NSSlider *chorusRateSlider;
	NSSlider *chorusDepthSlider;
	NSSlider *chorusMixLevel;
	
	NSTextField *chorusRateTitle;
	NSTextField *chorusDepthTitle;
	NSTextField *chorusMixTitle;
    
    NSTextField *chorusRateValue;
    NSTextField *chorusDepthValue;
    NSTextField *chorusMixValue;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupChorusRateUI];
    [self setupChorusDepthUI];
    [self setupMixLevelUI];
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

#pragma mark SETUP_UI

-(void) setupChorusRateUI {
    chorusRateTitle = [self drawLabelTextFieldWithRect:NSMakeRect(30, 320, 40, MAX_TEXTFIELD_HEIGHT)
                                             WithTitle:@"Rate"
                                                toView:self];
    
    chorusRateSlider = [self drawCircularSliderWithRect:NSMakeRect(30, 290, 30, 30)
                                             WithMaxVal:2.0
                                          AndWithMinVal:0.25
                                           atDefaultVal:1.0
                                                 toView:self
                                           withSelector:@selector(updateChorusRate:)];
    
    chorusRateValue = [self drawValueTextFieldWithRect:NSMakeRect(20, 260, 60, MAX_TEXTFIELD_HEIGHT)
                                                toView:self];
}

-(void) setupChorusDepthUI {
	chorusDepthTitle = [self drawLabelTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-25, 320, 50, MAX_TEXTFIELD_HEIGHT)
                                              WithTitle:@"Depth"
                                                 toView:self];
    
    chorusDepthSlider = [self drawCircularSliderWithRect:NSMakeRect(MAX_WIDTH/2-15, 290, 30, 30)
                                              WithMaxVal:40
                                           AndWithMinVal:20
                                            atDefaultVal:30
                                                  toView:self
                                            withSelector:@selector(updateChorusDepthLevel:)];
    
    chorusDepthValue = [self drawValueTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-30, 260, 60, MAX_TEXTFIELD_HEIGHT)
                                                 toView:self];
}

-(void) setupMixLevelUI {
	chorusMixTitle = [self drawLabelTextFieldWithRect:NSMakeRect(180, 320, 30, MAX_TEXTFIELD_HEIGHT)
                                            WithTitle:@"Mix"
                                               toView:self];
    
    chorusMixLevel = [self drawCircularSliderWithRect:NSMakeRect(180, 290, 30, 30)
                                           WithMaxVal:1.0
                                        AndWithMinVal:0.0
                                         atDefaultVal:1.0
                                               toView:self
                                         withSelector:@selector(updateMixLevel:)];
    
    chorusMixValue = [self drawValueTextFieldWithRect:NSMakeRect(170, 260, 60, MAX_TEXTFIELD_HEIGHT)
                                               toView:self];
}

#pragma mark IBACTION_CHORUS

-(IBAction) updateChorusRate:(id)sender {
    chorusRateValue.stringValue = [NSString stringWithFormat:@"%f", chorusRateSlider.floatValue];
    self.soundTabRef.soundBoard->setChorusModulationSpeed(chorusRateSlider.floatValue);
}

-(IBAction) updateChorusDepthLevel:(id)sender {
    chorusDepthValue.stringValue = [NSString stringWithFormat:@"%f", chorusDepthSlider.floatValue];
    self.soundTabRef.soundBoard->setChorusModulationDepth(chorusDepthSlider.floatValue);
}

-(IBAction) updateMixLevel:(id)sender {
    chorusMixValue.stringValue = [NSString stringWithFormat:@"%.02f %%", chorusMixLevel.floatValue * 100];
    self.soundTabRef.soundBoard->setChorusMixLevel(chorusMixLevel.floatValue);
}

@end








