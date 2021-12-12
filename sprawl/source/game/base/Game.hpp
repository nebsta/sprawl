//
//  Game.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 12/12/2021.
//  Copyright © 2021 The Caffeinated Coder. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>

#import "View.hpp"
#import "Object.hpp"
#import "SpriteManager.hpp"
#import "BlueprintManager.hpp"
#import "ScreenManager.hpp"

class Game : public Object {
    
public:
    Game(const int& screenWidth, const int& screenHeight);
    ~Game();
    
private:
    ScreenManager _screenManager;
    SpriteManager _spriteManager;
    BlueprintManager _blueprintManager;
    
    View _mainView;
    
};

#endif /* Game_hpp */
