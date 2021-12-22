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
    
    View *leftView = new View();
    leftView->renderer()->setTint(COLOR_CLEAR);
    leftView->transform().setSize(glm::vec2(screenWidth()*0.5f,screenHeight()));
    addChild(leftView);
    
    View *rightView = new View();
    rightView->renderer()->setTint(COLOR_CLEAR);
    rightView->transform().setLocalPosition(glm::vec2(screenWidth()*0.5,0.0f));
    rightView->transform().setSize(glm::vec2(screenWidth()*0.5f,screenHeight()));
    addChild(rightView);
    
    leftView->setOnTouchBegin([=](Touch touch) {
        Logger::logMessage("Left Input");
        if (_listener != nullptr) {
            _listener->onLeftInput();
        }
    });
    leftView->setId(390);
    
    rightView->setOnTouchBegin([=](Touch touch) {
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
