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

#include "Logger.h"
#include "SpriteHandler.hpp"

using namespace std;

class IOSSpriteHandler : public SpriteHandler {
    
public:
    IOSSpriteHandler();
    virtual ~IOSSpriteHandler();
    
    void loadAtlases();
    Sprite loadSprite(const string& file, const string& spriteName);
    
private:
    GLKTextureInfo* loadTexture(string filename) const;
    
    map<string, map<string,Region>> _allAtlases;
    
    void loadAtlas(string file);
    glm::vec2 parseAtlasSize(NSString *raw);
};

#endif /* SpriteManager_hpp */
