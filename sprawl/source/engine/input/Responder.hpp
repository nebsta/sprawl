//
//  Responder.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 14/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef Responder_hpp
#define Responder_hpp

#include <stdio.h>
#include <glm.hpp>
#include <functional>
#include <vector>

#include "Object.hpp"
#include "Touch.h"
#include "MathConstants.h"
#include "Transform.hpp"
#include "ViewHelper.hpp"

typedef std::function<void(Touch)> TouchCallback;

typedef enum ResponderState {
    ResponderState_None,
    ResponderState_Begin,
    ResponderState_End
} ResponderState;

#pragma mark Responder

class Responder : public Object {
    
public:
    Responder(const Transform& transform);
    ~Responder();
    
    void setOnTouchBeginCallback(TouchCallback callback);
    void setOnTouchEndCallback(TouchCallback callback);
    
    void onTouchBegin(Touch touch);
    void onTouchEnd(Touch touch);
    
    void addChild(Responder* const responder);
    
    bool hasChildren() const;
    
private:
    std::vector<Responder*> _children;
    
    const Transform& _transform;
    
    TouchCallback _onTouchBegin;
    TouchCallback _onTouchEnd;
};

#endif /* Responder_hpp */
