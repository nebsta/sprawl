//
//  Touch.h
//  sprawl
//
//  Created by Benjamin Wallis on 15/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef Touch_h
#define Touch_h

#include <glm.hpp>

#include "MathConstants.h"

struct Touch  {
    int id;
    glm::vec2 location;
};

const Touch TouchEmpty = {-1, VECTOR_EMPTY};

inline std::string touchToString(Touch touch) {
    std::stringstream stream;
    stream << "Touch { id: " << touch.id << " loc: " << touch.location.x << ", " << touch.location.y << " }";
    return stream.str();
}

#endif /* Touch_h */
