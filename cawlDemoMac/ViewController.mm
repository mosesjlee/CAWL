//
//  ViewController.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/31/16.
//  Copyright © 2016 Moses Lee. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController {
}

- (void)viewDidLoad {
	[super viewDidLoad];
    _cawlInstance = CAWL::Instance();
    _numChannels = _cawlInstance->getNumChannels();
    _soundPageArray = [[NSMutableArray alloc] init];
    _channelActivationButtons = [[NSMutableArray alloc] init];
    for(unsigned i = 0; i < _numChannels; i++) {
        [_soundPageArray addObject:[[SoundTab alloc] init]];
        [_soundPageArray objectAtIndex:i].label = [NSString stringWithFormat:@"Channel %d", i+1];
        [_tabbedView insertTabViewItem:[_soundPageArray objectAtIndex:i] atIndex:i];
    }
    [self setupChannelActivationButtons];
    _isPlaying = NO;

    //Just register here for now
    _cawlInstance->registerInputBlockAtInputChannel([[_soundPageArray objectAtIndex:0] getSoundBoardRef], 0);
    NSLog(@"Finished setting up View");
}

- (void)viewWillAppear
{
    [super viewWillAppear];
}

- (void)setupChannelActivationButtons {
    for(unsigned i = 0; i < _numChannels; i++) {
        [_channelActivationButtons addObject:[[NSButton alloc] initWithFrame:NSMakeRect(400 + (i * 175), 10, 165, 50)]];
        [self.view addSubview:[_channelActivationButtons objectAtIndex:i]];
        [[_channelActivationButtons objectAtIndex:i] setButtonType:NSPushOnPushOffButton];
        [[_channelActivationButtons objectAtIndex:i] setBezelStyle:NSBezelStyleRoundRect];
        [[_channelActivationButtons objectAtIndex:i] setTitle:[NSString stringWithFormat:@"Channel %d", i + 1]];
        [[_channelActivationButtons objectAtIndex:i] setAction:@selector(updateChannelOnOff)];
        [[_channelActivationButtons objectAtIndex:i] setNeedsDisplay:YES];
    }
}

- (void)setRepresentedObject:(id)representedObject {
	[super setRepresentedObject:representedObject];

	// Update the view, if already loaded.
}

- (void) updateChannelOnOff {
    NSLog(@"On off");
}

- (IBAction)playStopAction:(id)sender {
    
    //If its playing then stop
    if(_isPlaying) {
        _playStopButton.title = @"Play";
        _cawlInstance->stopPlaying();
    }
    //If its not playing then play
    else {
        _playStopButton.title = @"Stop";
        _cawlInstance->startPlaying();
    }
    _isPlaying =! _isPlaying;
}

- (void)registerInputChannel {
    //_cawlInstance->registerInputBlockAtInputChannel(<#^(float *buffer, const unsigned int numSamples)buffer#>, <#const unsigned int channel#>);
}

@end
