//
//  MetalRootViewController.m
//  sprawl_metal
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#import "MetalRootViewController.h"

#define MS_PER_UPDATE 30

@interface MetalRootViewController ()
@property(nonatomic,readwrite) float frameLag;
@end

@implementation MetalRootViewController

- (void)viewDidLoad {
    [super viewDidLoad];

//    ScreenManager::instance().initialize([[UIScreen mainScreen] scale], self.view.frame.size.width, self.view.frame.size.height);
//
//    ShaderManager::instance().initialize();
//    _game = new Game(ScreenManager::instance(), _spriteManager);
}

- (void)dealloc {

    delete _game;
    _game = nullptr;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];

}

- (BOOL)prefersStatusBarHidden {
    return YES;
}

- (void)update {

//    self.frameLag += self.timeSinceLastUpdate;
//
//    while (self.frameLag * 1000 >= MS_PER_UPDATE) {
//        _game->update(MS_PER_UPDATE / 1000.0);
//        self.frameLag -= MS_PER_UPDATE/1000.0;
//    }
}

#pragma mark UIGestureRecognizer

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {

//    NSSet *set = [event touchesForView:self.view];
//    if ([set count] > 0) {
//        UITouch *touch = [set anyObject];
//        CGPoint location = [touch locationInView:self.view];
//        Touch data = {(int)touch.hash,glm::vec2(location.x,location.y)};
//        _mainView->touchBegin(data);
//    }
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {

//    NSSet *set = [event touchesForView:self.view];
//    if ([set count] > 0) {
//        UITouch *touch = [set anyObject];
//        CGPoint location = [touch locationInView:self.view];
//        Touch data = {(int)touch.hash,glm::vec2(location.x,location.y)};
//        _mainView->touchEnd(data);
//    }
}

- (void)touchesCancelled:(NSSet<UITouch*>*)touches withEvent:(UIEvent *)event {

    NSSet *set = [event touchesForView:self.view];
    if ([set count] > 0) {
//        UITouch *touch = [set anyObject];
//        CGPoint location = [touch locationInView:self.view];
//        Touch data = {(int)touch.hash,glm::vec2(location.x,location.y)};
    }
}

@end
