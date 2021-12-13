//
//  View.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef View_hpp
#define View_hpp

#include <stdio.h>
#include <glm.hpp>
#include <vector>

#include "Object.hpp"
#include "Transform.hpp"
#include "Responder.hpp"
#include "ViewRenderer.hpp"
#include "ViewAnimator.hpp"
#include "ScreenManager.hpp"

#include "ColorConstants.h"
#include "MathConstants.h"

#include "ViewHelper.hpp"

#define VIEW_DEFAULT_COLOR COLOR_WHITE
#define VIEW_DEFAULT_POSITION glm::vec2(0,0)
#define VIEW_DEFAULT_SIZE glm::vec2(10,10)

class View : public Object {
    
public:
    View();
    View(glm::vec2 position);
//    View(glm::vec2 position, glm::vec2 size);
    View(glm::vec2 position, glm::vec2 size, glm::vec4 color);
    View(glm::vec2 position, glm::vec2 size);
    
    void render();
    void update(float dt);
    
    void setViewConstraint(TransformConstraint constraint);
    
    void touchBegin(Touch touch);
    void touchEnd(Touch touch);
    
    void setOnTouchBegin(std::function<void(Touch)> callback);
    void setOnTouchEnd(std::function<void(Touch)> callback);
    
    void addChild(View* const view);
    void removeChild(View* const view);
    bool hasChildren() const;
    
    Transform& transform();
    Renderer& renderer();
    Responder& responder();
    ViewAnimator& animator();
    
protected:
    Renderer _renderer;
    Transform _transform;
    ViewAnimator _animator;
    Responder _responder;
    
    void consumeTransformChanges();
    void refreshRendererMatrix();
    void refreshRendererClip();
    
    float screenWidth() const;
    float screenHeight() const;
    glm::vec2 screenSize() const;
    
private:
    std::vector<View*> _children;
    
    const ScreenManager& _screenManager;
};

#endif /* View_hpp */
