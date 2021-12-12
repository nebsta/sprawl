//
//  SpriteManager.mm
//  sprawl
//
//  Created by Benjamin Wallis on 8/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "SpriteManager.hpp"

SpriteManager::SpriteManager() {
    parseAtlas("main_tileset_hd");
}

SpriteManager::~SpriteManager() {
    parseAtlas("main_tileset_hd");
}

GLKTextureInfo* SpriteManager::loadTexture(string filename) const {
    
    NSError *err;
    NSString *filePath = [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:filename.c_str()] ofType:@"png"];
    if (filePath == nil) {
        Logger::logError("Unable to find texture");
        return nullptr;
    }
    
    GLKTextureInfo *texture = [GLKTextureLoader textureWithContentsOfFile:filePath options:nil error:&err];
    if (err != nullptr) {
        Logger::logError("Error loading texture.");
        return nullptr;
    }
    
    return texture;
}

Sprite SpriteManager::loadSprite(const string& file, const string& spriteName) const {
    GLKTextureInfo *texture = loadTexture(file);
    Region region = _allAtlases.at(file).at(spriteName);
    return {texture,region};
}

glm::vec2 SpriteManager::parseAtlasSize(NSString *raw) {
    glm::vec2 size;

    raw = [raw substringWithRange:NSMakeRange(1, raw.length-2)];
    NSArray *comps = [raw componentsSeparatedByString:@","];
    size.x = [[comps objectAtIndex:0] intValue];
    size.y = [[comps objectAtIndex:1] intValue];
    
    return size;
}

void SpriteManager::parseAtlas(string file) {
    NSString *path = [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:file.c_str()] ofType:@"plist"];
    NSDictionary *root = [NSDictionary dictionaryWithContentsOfFile:path];
    NSDictionary *frames = [root objectForKey:@"frames"];
    NSDictionary *metadata = [root objectForKey:@"metadata"];
    glm::vec2 size = parseAtlasSize([metadata objectForKey:@"size"]);
    
    map<string,Region> atlas;
    for (NSString  *key in frames.allKeys) {
        NSDictionary *dict = [frames objectForKey:key];
        Region region;
        
        float offsetX = [[dict objectForKey:@"spriteOffsetX"] floatValue];
        float offsetY = [[dict objectForKey:@"spriteOffsetY"] floatValue];
        float width = [[dict objectForKey:@"spriteSizeW"] floatValue];
        float height = [[dict objectForKey:@"spriteSizeH"] floatValue];
        
        region.x = offsetX / size.x;
        region.y = offsetY / size.y;
        region.w = width / size.x;
        region.h = height / size.y;
        
        atlas[key.UTF8String] = region;
    }
    
    _allAtlases[file] = atlas;
}
