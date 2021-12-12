//
//  SpriteManager.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 8/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef SpriteManager_hpp
#define SpriteManager_hpp

#include <stdio.h>
#include <string>
#include <glm.hpp>
#include <map>

#include "Sprite.h"
#include "Logger.h"
#include "SpriteLoader.h"

using namespace std;

class SpriteManager : public SpriteLoader {
    
public:
    SpriteManager();
    ~SpriteManager();
    
    GLKTextureInfo* loadTexture(string filename) const;
    Sprite loadSprite(const string& file, const string& spriteName) const;
    
private:
    map<string, map<string,Region>> _allAtlases;
    
    void parseAtlas(string file);
    glm::vec2 parseAtlasSize(NSString *raw);
};

#endif /* SpriteManager_hpp */
