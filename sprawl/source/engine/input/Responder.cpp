//
//  Responder.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 14/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Responder.hpp"

typedef std::vector<Responder*>::iterator ResponderIterator;

Responder::Responder() {
    
}

Responder::Responder(Transform *transform) :
_transform(transform),
_onTouchBegin(nullptr),
_onTouchEnd(nullptr) {
    
}

Responder::~Responder() {
    _children.clear();
    
    _onTouchBegin = nullptr;
    _onTouchEnd = nullptr;
    _transform = nullptr;
}

void Responder::setOnTouchBeginCallback(TouchCallback callback) {
    _onTouchBegin = callback;
}

void Responder::setOnTouchEndCallback(TouchCallback callback) {
    _onTouchEnd = callback;
}

void Responder::setTransform(Transform *transform) {
    _transform = transform;
}

void Responder::onTouchBegin(Touch touch) {
    
    if (_transform == nullptr) {
        return;
    }
    
    if (!_transform->containsScreenPoint(touch.location)) {
        return;
    }
    
    // send callback
    if (_onTouchBegin != nullptr) {
        _onTouchBegin(touch);
    }
    
    // pass the touch to the child nodes
    if (hasChildren()) {
        ResponderIterator iter = _children.begin();
        for (; iter != _children.end(); iter++) {
            (*iter)->onTouchBegin(touch);
        }
    }
}

void Responder::onTouchEnd(Touch touch) {
    
//    glm::vec2 relativePos = ViewHelper::convertToSpace(touch.location, _transform->parent(), _transform);
//    Touch relativeTouch = {touch.id,relativePos};
//    
//    if (_transform->containsLocalPoint(touch.location)) {
//        _responder->onTouchEnd(touch);
//    }
//    
//    if (_node != nullptr && _node->hasChildren()) {
//        _node->processTouchEndChildren(relativeTouch);
//    }
    
}

void Responder::addChild(Responder *responder) {
    _children.push_back(responder);
}

bool Responder::hasChildren() {
    return _children.size() != 0;
}
