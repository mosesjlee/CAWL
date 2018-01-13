//
//  AmpUI.h
//  cawlDemoMac
//
//  Created by Moses Lee on 10/13/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "EffectUI.h"

@interface AmpUI : EffectUI
- (instancetype)initWithFrame:(NSRect)frameRect;
- (void)setAmpTitle:(NSString*)title;
@end
