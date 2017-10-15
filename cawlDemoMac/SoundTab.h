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

@interface SoundTab : NSTabViewItem
- (instancetype)initWithIdentifier:(id)identifier;
- (void)drawLabel:(BOOL)shouldTruncateLabel
           inRect:(NSRect)labelRect;
- (cawlBuffers) getSoundBoardRef;

@property (strong) NSPopUpButton * ampSelector;
@property (strong) NSPopUpButton * effectSelector1;
@property (strong) NSPopUpButton * effectSelector2;
@property (strong) NSPopUpButton * effectSelector3;
@property (strong) NSPopUpButton * effectSelector4;

@property CAWLSoundBoard soundBoard;
@property cawlBuffers buffer;
@end
