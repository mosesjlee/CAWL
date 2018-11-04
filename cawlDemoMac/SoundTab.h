//
//  SoundTab.h
//  cawlDemoMac
//
//  Created by Moses Lee on 10/12/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "CAWLSoundBoard.hpp"
#import "CAWL.hpp"
#define MAX_HEIGHT  360
#define MAX_WIDTH   250
@interface SoundTab : NSTabViewItem
- (instancetype)initWithIdentifier:(id)identifier;
- (void)drawLabel:(BOOL)shouldTruncateLabel
           inRect:(NSRect)labelRect;
- (cawlBuffer) getSoundBoardRef;

@property (strong) NSPopUpButton * ampSelector;
@property (strong) NSPopUpButton * effectSelector1;
@property (strong) NSPopUpButton * effectSelector2;
@property (strong) NSPopUpButton * effectSelector3;
@property (strong) NSPopUpButton * effectSelector4;

@property CAWLSoundBoard * soundBoard;
@property (copy) cawlBuffer buffer;
@end
