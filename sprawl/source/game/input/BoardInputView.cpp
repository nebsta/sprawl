//
//  BoardInputView.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 28/02/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#include "BoardInputView.hpp"

BoardInputView::BoardInputView() : View() {
    
    _transform.setSize(screenSize());
    
    _leftView.renderer().setTint(COLOR_CLEAR);
    _leftView.transform().setSize(glm::vec2(screenWidth()*0.5f,screenHeight()));
    addChild(_leftView);
    
    _rightView.renderer().setTint(COLOR_CLEAR);
    _rightView.transform().setLocalPosition(glm::vec2(screenWidth()*0.5,0.0f));
    _rightView.transform().setSize(glm::vec2(screenWidth()*0.5f,screenHeight()));
    addChild(_rightView);
    
    _leftView.setOnTouchBegin([=](Touch touch) {
        Logger::logMessage("Left Input");
        if (_listener != nullptr) {
            _listener->onLeftInput();
        }
    });
    _leftView.setId(390);
    
    _rightView.setOnTouchBegin([=](Touch touch) {
        Logger::logMessage("Right Input");
        if (_listener != nullptr) {
            _listener->onRightInput();
        }
    });
}

BoardInputView::~BoardInputView() {
    _listener = nullptr;
}

void BoardInputView::setBoardInputListener(BoardInputListener *listener) {
    _listener = listener;
}
