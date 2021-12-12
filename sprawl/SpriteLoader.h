//
//  SpriteLoader.h
//  sprawl
//
//  Created by Benjamin Wallis on 12/12/2021.
//  Copyright © 2021 The Caffeinated Coder. All rights reserved.
//

#ifndef SpriteLoader_h
#define SpriteLoader_h

#import "Sprite.h"

class SpriteLoader {
public:
    virtual Sprite loadSprite(const std::string& file, const std::string& spriteName) const = 0;
};

#endif /* SpriteLoader_h */
