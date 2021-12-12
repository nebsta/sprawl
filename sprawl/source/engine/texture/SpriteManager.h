//
//  SpriteManager.h
//  sprawl
//
//  Created by Benjamin Wallis on 8/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef SpriteManager_h
#define SpriteManager_h

#include <stdio.h>
#include <string>
#include <glm.hpp>
#include <map>

#include "Sprite.h"
#include "Logger.h"

using namespace std;

class SpriteManager {
    
public:
    static SpriteManager& instance() {
        static SpriteManager instance;
        return instance;
    }
    
    void initialize();
    
    GLKTextureInfo* loadTexture(string filename);
    Sprite loadSprite(string file, string spriteName);
    
private:
    map<string, map<string,Region>> _allAtlases;
    
    void parseAtlas(string file);
    glm::vec2 parseAtlasSize(NSString *raw);
};

#endif /* SpriteManager_h */
