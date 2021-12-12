//
//  BoardManager.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "BoardManager.hpp"

void BoardManager::initialize() {
    _dataModel = new BoardDataModel();
    _boardView = new BoardView();
}

void BoardManager::teardown() {
    delete _dataModel;
    _dataModel = nullptr;
    
    delete _boardView;
    _boardView = nullptr;
}

#pragma mark Getters

BoardView* BoardManager::boardView() {
    return _boardView;
}
