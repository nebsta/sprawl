//
//  View.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "View.hpp"

typedef std::vector<View*>::iterator ViewIterator;

View::View() : View(VIEW_DEFAULT_POSITION) {
    
}

View::View(glm::vec2 position) : View(position,VIEW_DEFAULT_SIZE) {
    
}

View::View(glm::vec2 position, glm::vec2 size) : View(position,size,VIEW_DEFAULT_COLOR) {
    
}

View::View(glm::vec2 position, glm::vec2 size, glm::vec4 color) : View(position,size,color,new ViewRenderer(color))
{

}

View::View(glm::vec2 position, glm::vec2 size, glm::vec4 color, Renderer *renderer) :
_renderer(renderer),
_animator(new ViewAnimator()),
_transform(new Transform(position,size)),
_responder(new Responder(_transform)),
_screenManager(ScreenManager::instance()) {
    _renderer->setTint(color);
    refreshRendererMatrix();
    refreshRendererClip();
}

View::~View() {
    delete _renderer;
    _renderer = nullptr;
    
    delete _animator;
    _animator = nullptr;
    
    delete _transform;
    _transform = nullptr;
    
    delete _responder;
    _responder = nullptr;
}

void View::render() {
    if (_renderer != nullptr) {
        _renderer->render();
        
        _renderer->pushClippingRect();
        
        if (hasChildren()) {
            for (ViewIterator iter = _children.begin(); iter != _children.end(); iter++) {
                (*iter)->render();
            }
        }
        
        _renderer->popClippingRect();
    }
}

void View::update(float dt) {
    
    if (_animator != nullptr && _animator->isPlaying()) {
        
        if (!_animator->hasStarted()) {
          _animator->setup(_transform->localPosition(), _transform->size());
        }
        
        _animator->update(dt);
        _transform->setLocalPosition(_animator->resultPosition());
        _transform->setSize(_animator->resultSize());
    }
    
    if (_transform->consumePropertyChanges()) {
        refreshRendererMatrix();
        refreshRendererClip();
    
        if (_animator != nullptr && !_animator->isPlaying()) {
            _animator->setStartPosition(_transform->localPosition());
            _animator->setEndPosition(_transform->localPosition());
            _animator->setStartSize(_transform->size());
            _animator->setEndSize(_transform->size());        }
    }
  
    if (hasChildren()) {
        for (ViewIterator iter = _children.begin(); iter != _children.end(); iter++) {
            (*iter)->update(dt);
        }
    }
}

void View::consumeTransformChanges() {

}

#pragma mark Renderer Refreshing

void View::refreshRendererMatrix() {
    if (_renderer != nullptr && _transform != nullptr) {
        glm::mat4 matrix = _transform->matrix();
        _renderer->setModelviewMatrix(matrix);
    }
    
    if (hasChildren()) {
        for (ViewIterator iter = _children.begin(); iter != _children.end(); iter++) {
            (*iter)->refreshRendererMatrix();
        }
    }
}

void View::refreshRendererClip() {
    if (_renderer != nullptr && _transform != nullptr) {
        glm::vec4 rect = _transform->rect();
        _renderer->setClippingRect(rect);
    }
    
    if (hasChildren()) {
        for (ViewIterator iter = _children.begin(); iter != _children.end(); iter++) {
            (*iter)->refreshRendererClip();
        }
    }
}

#pragma mark Input

void View::touchBegin(Touch touch) {
    if (_responder != nullptr) {
        _responder->onTouchBegin(touch);
    }
}

void View::touchEnd(Touch touch) {
    if (_responder != nullptr) {
        _responder->onTouchEnd(touch);
    }
}

void View::setOnTouchBegin(std::function<void (Touch)> callback) {
    if (_responder != nullptr) {
        _responder->setOnTouchBeginCallback(callback);
    }
}

void View::setOnTouchEnd(std::function<void (Touch)> callback) {
    if (_responder != nullptr) {
        _responder->setOnTouchEndCallback(callback);
    }
}

#pragma mark Child Management

void View::addChild(View *child) {
    ViewIterator pos = std::find(_children.begin(), _children.end(), child);
    if (pos != _children.end()) {
        return;
    }
    _children.push_back(child);
  
    child->transform()->setParent(_transform);
    
    if (_responder != nullptr) {
        _responder->addChild(child->responder());
    }
    
    refreshRendererMatrix();
    refreshRendererClip();
}

void View::removeChild(View *child) {
    ViewIterator pos = std::find(_children.begin(), _children.end(), child);
    if (pos == _children.end()) {
        return;
    }
    _children.erase(pos);
  
    child->transform()->setParent(nullptr);
    
    refreshRendererMatrix();
    refreshRendererClip();
}

bool View::hasChildren() {
    return _children.size() != 0;
}

#pragma mark Getters

Transform* View::transform() {
    return _transform;
}

Renderer* View::renderer() {
    return _renderer;
}

Responder* View::responder() {
    return _responder;
}

ViewAnimator* View::animator() {
    return _animator;
}

float View::screenWidth() const {
    return _screenManager.screenWidth();
}

float View::screenHeight() const {
    return _screenManager.screenHeight();
}

glm::vec2 View::screenSize() const {
    return _screenManager.screenSize();
}
