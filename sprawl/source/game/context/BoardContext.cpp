//
//  BoardContext.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 30/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#include "BoardContext.hpp"

BoardContext::BoardContext() :
_boardDataModel(new BoardDataModel()) {
    
}

BoardContext::~BoardContext() {
    delete _boardDataModel;
    _boardDataModel = nullptr;
    
    delete _boardView;
    _boardView = nullptr;
}

void BoardContext::init() {
    
}

void BoardContext::initWithView(View *view) {
    
//    _boardView = new BoardView();
//    _boardDataModel->setListener(_boardView);
//    view->addChild(_boardView);
    
//    _boardInputView = new BoardInputView();
//    view->addChild(_boardInputView);
//
//    BlueprintDataModel blueprint = BlueprintManager::instance().getRandomBlueprint();
//    _boardDataModel->addBlueprint(blueprint);
}
