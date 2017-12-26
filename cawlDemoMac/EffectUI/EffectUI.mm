//
//  EffectUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/22/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "EffectUI.h"

@implementation EffectUI
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    // Drawing code here.
}

- (NSSlider *)drawCircularSliderWithRect:(NSRect) rect
                              WithMaxVal:(float) max
                           AndWithMinVal:(float) min
                            atDefaultVal:(float) val
                                  toView:(NSView *) theView
                            withSelector:(SEL) selector
{
    NSSlider * retval = [[NSSlider alloc] initWithFrame:rect];
    [retval setSliderType:NSSliderTypeCircular];
    [retval setMaxValue:max];
    [retval setMinValue:min];
    [retval setNeedsDisplay:YES];
    [retval setFloatValue:val];
    [retval setTarget:theView];
    [retval setAction:selector];
    [theView addSubview:retval];
    return retval;
}

- (NSSlider *)drawRegularSliderWithRect:(NSRect) rect
                             WithMaxVal:(float) max
                          AndWithMinVal:(float) min
                           atDefaultVal:(float) val
                                 toView:(NSView *) theView
                           withSelector:(SEL) selector
{
    NSSlider * retval = [[NSSlider alloc] initWithFrame:rect];
    [retval setMaxValue:max];
    [retval setMinValue:min];
    [retval setNeedsDisplay:YES];
    [retval setTarget:theView];
    [retval setAction:selector];
    retval.frameRotation = 90.0;
    [theView addSubview:retval];
    return retval;
}

- (NSTextField *)drawLabelTextFieldWithRect:(NSRect) rect
                                  WithTitle:(NSString *)title
                                     toView:(NSView *)theView
{
    NSTextField * retval = [[NSTextField alloc] initWithFrame:rect];
    retval.stringValue = title;
    [retval setEditable:NO];
    [retval setBordered:NO];
    [retval setDrawsBackground:NO];
    [retval setNeedsDisplay:YES];
    retval.alignment = NSTextAlignmentCenter;
    [theView addSubview:retval];
    [retval setTarget:theView];
    return retval;
}

- (NSTextField *)drawValueTextFieldWithRect:(NSRect) rect
                                     toView:(NSView *)theView
{
    NSTextField * retval = [[NSTextField alloc] initWithFrame:rect];
    [retval setNeedsDisplay:YES];
    [retval setTarget:theView];
    [theView addSubview:retval];
    return retval;
}

//From question:
//https://stackoverflow.com/questions/5004960/adding-border-and-rounded-rect-in-the-nsview
-(void)drawBorder:(NSRect)rect{
    NSRect frameRect = [self bounds];
    
    if(rect.size.height < frameRect.size.height)
        return;
    NSRect newRect = NSMakeRect(rect.origin.x+2, rect.origin.y+2, rect.size.width-2, rect.size.height-2);
    
    NSBezierPath *textViewSurround = [NSBezierPath bezierPathWithRoundedRect:newRect xRadius:10 yRadius:10];
    [textViewSurround setLineWidth:3];
    //[pBorderColor set];
    [textViewSurround stroke];
    [self setWantsLayer: YES];
    [self.layer setBorderWidth: 2];
    [self.layer setCornerRadius: 10];
}

@end
