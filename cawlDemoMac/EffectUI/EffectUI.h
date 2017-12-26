//
//  EffectUI.h
//  cawlDemoMac
//
//  Created by Moses Lee on 10/22/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SoundTab.h"
#define MAX_TEXTFIELD_HEIGHT 25


@interface EffectUI : NSView
@property SoundTab *soundTabRef;
- (NSSlider *)drawCircularSliderWithRect:(NSRect) rect
                              WithMaxVal:(float) max
                           AndWithMinVal:(float) min
                            atDefaultVal:(float) val
                                  toView:(NSView *) theView
                            withSelector:(SEL) selector;

- (NSSlider *)drawRegularSliderWithRect:(NSRect) rect
                             WithMaxVal:(float) max
                          AndWithMinVal:(float) min
                           atDefaultVal:(float) val
                                 toView:(NSView *) theView
                           withSelector:(SEL) selector;

- (NSTextField *)drawLabelTextFieldWithRect:(NSRect) rect
                                  WithTitle:(NSString *)title
                                     toView:(NSView *) theView;

- (NSTextField *)drawValueTextFieldWithRect:(NSRect) rect
                                     toView:(NSView *) theView;

-(void)drawBorder:(NSRect)rect;
@end

