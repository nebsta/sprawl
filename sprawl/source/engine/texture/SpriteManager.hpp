//
//  SpriteManager.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#ifndef SpriteManager_hpp
#define SpriteManager_hpp

#include <stdio.h>
#include <string>
#include <glm.hpp>
#include <map>

#include "Sprite.h"
#include "SpriteHandler.hpp"
#include "Logger.h"

using namespace std;

class SpriteManager {
    
public:
    SpriteManager();
    ~SpriteManager();
    
    Sprite loadSprite(const string& file, const string& spriteName) const;
    
private:
    unique_ptr<SpriteHandler> _spriteHandler;
    
    map<string, map<string,Region>> _allAtlases;
    
    void parseAtlas(string file);
    glm::vec2 parseAtlasSize(NSString *raw);
};

#endif /* SpriteManager_hpp */

