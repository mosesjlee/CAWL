//
//  DelayUI.h
//  cawlDemoMac
//
//  Created by Moses Lee on 10/13/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SoundTab.h"

@interface DelayUI : NSView
- (instancetype)initWithFrame:(NSRect)frameRect;
@property SoundTab * soundTabRef;
@end
