//
//  Game.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 12/12/2021.
//  Copyright © 2021 The Caffeinated Coder. All rights reserved.
//

#include "Game.hpp"

Game::Game(const ScreenHandler& screenHandler, const SpriteLoader& spriteLoader) :
_mainView(VECTOR_EMPTY,glm::vec2(screenHandler.screenWidth(),screenHandler.screenHeight())),
_screenHandler(screenHandler),
_spriteLoader(spriteLoader),
_boardView(_boardDataModel, spriteLoader) {
    
    _mainView.renderer()->setTint(COLOR_RED);
    
    _mainView.addChild(&_boardView);
    
    BlueprintDataModel blueprint = _blueprintManager.getRandomBlueprint();
    _boardDataModel.addBlueprint(blueprint);
}


void Game::update(const float& dt) {
    _mainView.update(dt);
}

void Game::render() {
    _mainView.render();
}
