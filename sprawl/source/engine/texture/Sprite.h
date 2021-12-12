//
//  Sprite.h
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef Sprite_h
#define Sprite_h

#include <GLKit/GLKit.h>
#include <stdio.h>

typedef struct Region {
    float x, y, w, h;
} Region;

typedef struct Sprite {
    GLKTextureInfo *texture;
    Region textureRegion;
} Sprite;

const Sprite SpriteEmpty = { nullptr, {0, 0, 0, 0} };

inline bool operator==(const Sprite& s1, const Sprite& s2)
{
    if (s1.texture == nullptr && s2.texture == nullptr) {
        return true;
    } else if (s1.texture == nullptr || s2.texture == nullptr) {
        return false;
    }
    
    return s1.texture.target == s2.texture.target;
}

inline bool isSpriteEmpty(Sprite sprite) {
    return sprite.texture == nullptr;
}

#endif /* Sprite_h */
