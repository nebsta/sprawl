//
//  MetalRootViewController.h
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#import <UIKit/UIKit.h>

#include "Logger.h"
#include "Game.hpp"

@interface MetalRootViewController : UIViewController {
    
}
@property (nonatomic) Game *game;
@property (nonatomic) ScreenManager screenManager;
@end
