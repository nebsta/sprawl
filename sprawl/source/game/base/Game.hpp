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
#import "SpriteLoader.h"
#import "BlueprintManager.hpp"
#import "ScreenHandler.h"
#import "BoardDataModel.hpp"
#import "BoardView.hpp"

class Game : public Object {
    
public:
    Game(const ScreenHandler& screenHandler, const SpriteLoader& spriteLoader);
    ~Game();
    
    void update(const float& dt);
    void render();
    
private:
    const ScreenHandler &_screenHandler;
    const SpriteLoader &_spriteLoader;
    BlueprintManager _blueprintManager;
    
    View _mainView;
//    BoardView _boardView;
    BoardDataModel _boardDataModel;
};

#endif /* Game_hpp */
