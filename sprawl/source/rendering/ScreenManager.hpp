//
//  ScreenManager.hpp
//  sprawl
//
//  Created by Benjamin on 26/01/2019.
//  Copyright © 2019 The Caffeinated Coder. All rights reserved.
//

#ifndef ScreenManager_hpp
#define ScreenManager_hpp

#include <stdio.h>
#include <glm.hpp>
#include "MathConstants.h"
#include "ScreenHandler.h"

class ScreenManager : public ScreenHandler {
    
public:
    static ScreenManager& instance() {
        static ScreenManager instance;
        return instance;
    }
    
    void initialize(const float screenScale, const float screenWith, const float screenHeight);
    
    // ScreenHandler
    glm::vec2 convertToPixels(const glm::vec2& vector) const;
    
    float screenScale() const;
    float screenWidth() const;
    float screenHeight() const;
    
    glm::vec2 screenPixelSize() const;
    glm::vec2 screenSize() const;
    
private:
    bool _initialized = false;
    
    float _screenScale;
    float _screenWidth;
    float _screenHeight;
};

#endif /* ScreenManager_hpp */
