//
//  SpriteManager.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#include "SpriteManager.hpp"

#ifdef PLATFORM_IOS
#import "IOSSpriteManager.hpp"
#endif

SpriteManager::SpriteManager()
{
#ifdef PLATFORM_IOS
    _spriteHandler(new IOSSpriteManager());
#endif
    
    _spriteHandler->loadAtlases();
}

SpriteManager::~SpriteManager() {
    
}

Sprite SpriteManager::loadSprite(const string &file, const string &spriteName) const {
    
    return SpriteEmpty;
}
