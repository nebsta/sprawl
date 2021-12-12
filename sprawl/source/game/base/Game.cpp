//
//  Game.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 12/12/2021.
//  Copyright © 2021 The Caffeinated Coder. All rights reserved.
//

#include "Game.hpp"

Game::Game(const int& screenWidth, const int& screenHeight) :
_mainView(VECTOR_EMPTY,glm::vec2(screenWidth,screenHeight)) {
    
    _mainView.renderer()->setTint(COLOR_RED);
    
//    BoardDataModel model;
//    _boardView = new BoardView(model);
//    _mainView->addChild(_boardView);
    
//    BlueprintDataModel blueprint = BlueprintManager::instance().getRandomBlueprint();
//    model.addBlueprint(blueprint);
}
