//
//  ViewController.h
//  cawlDemoMac
//
//  Created by Moses Lee on 10/31/16.
//  Copyright © 2016 Moses Lee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SoundTab.h"
#import "CAWL.hpp"

@interface ViewController : NSViewController {
    CAWLSoundBoard board;
    cawlBuffers ca;
}
@property (weak) IBOutlet NSTabView *tabbedView;
@property NSMutableArray<SoundTab *> * soundPageArray;
@property NSMutableArray<NSButton *> * channelActivationButtons;
@property unsigned int numChannels;
@property CAWL * cawlInstance;
@property (weak) IBOutlet NSButton *playStopButton;
@property BOOL isPlaying;
@end

