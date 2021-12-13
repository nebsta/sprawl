//
//  RootViewController.h
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

#include "Logger.h"

#include "Game.hpp"

@interface RootViewController : GLKViewController {
    glm::mat4 _projectionMatrix;
}
@property (strong, nonatomic) EAGLContext *context;
@property (nonatomic) Game *game;
@property (nonatomic) View *someView;
@property (nonatomic) SpriteManager spriteManager;
@property (nonatomic) ScreenManager screenManager;
- (void)setupOpenGL;
- (void)tearDownGL;
@end
