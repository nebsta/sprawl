//
//  ScreenManager.cpp
//  sprawl
//
//  Created by Benjamin on 26/01/2019.
//  Copyright © 2019 The Caffeinated Coder. All rights reserved.
//

#include "ScreenManager.hpp"

void ScreenManager::initialize(const float screenScale, const float screenWith, const float screenHeight) {
    _screenScale = screenScale;
    _screenWidth = screenWith;
    _screenHeight = screenHeight;
}

glm::vec2 ScreenManager::screenPixelSize() const {
    static glm::vec2 screenSizePixels = VECTOR_EMPTY;
    if (screenSizePixels == VECTOR_EMPTY) {
        screenSizePixels = glm::vec2(_screenWidth*_screenScale,_screenHeight*_screenScale);
    }
    return screenSizePixels;
}

glm::vec2 ScreenManager::screenSize() const {
    static glm::vec2 screenSize = VECTOR_EMPTY;
    if (screenSize == VECTOR_EMPTY) {
        screenSize = glm::vec2(_screenWidth,_screenHeight);
    }
    return screenSize;
}

glm::vec2 ScreenManager::convertToPixels(const glm::vec2& vector) const {
    return vector * _screenScale;
}

#pragma mark Getters

float ScreenManager::screenWidth() const {
    return _screenWidth;
}

float ScreenManager::screenHeight() const {
    return _screenHeight;
}

float ScreenManager::screenScale() const {
    return _screenScale;
}

//glm::vec2 ScreenManager::localToScreenSpace(glm::vec2 pos, Transform *transform) {
//    return glm::vec2();
//}
//
//glm::vec2 ScreenManager::screenToLocalSpace(glm::vec2 pos, Transform *transform) {
//    return glm::vec2();
//}
//
//glm::vec2 ScreenManager::convertToSpace(glm::vec2 pos, Transform *origin, Transform *target) {
//    if (origin == nullptr) {
//        return pos;
//    }
//    glm::vec2 diff = target->position() - origin->position();
//    return pos - diff;
//}
