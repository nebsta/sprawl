//
//  ImageViewRenderer.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 8/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef ImageViewRenderer_hpp
#define ImageViewRenderer_hpp

#include <stdio.h>

#include "Renderer.hpp"
#include "Sprite.h"

#define IMAGEVIEW_RENDERER_DEFAULT_COLOR COLOR_WHITE
#define IMAGEVIEW_RENDERER_DEFAULT_SHAPE Square
#define IMAGEVIEW_RENDERER_DEFAULT_SPRITE SpriteEmpty
#define IMAGEVIEW_RENDERER_DEFAULT_SHADER "ImageViewShader"

class ImageViewRenderer : public Renderer {
    
public:
    ImageViewRenderer();
    ImageViewRenderer(Mesh mesh);
    ImageViewRenderer(Sprite sprite);
    ImageViewRenderer(Mesh mesh, Sprite sprite);
    ImageViewRenderer(Mesh mesh, Sprite sprite, glm::vec4 tint);
    ~ImageViewRenderer();
    
    void refreshTextureCoords();
    
    void setSprite(Sprite sprite);
    
private:
    Sprite _sprite;
    
protected:
    void setupAttribPointers();
    void onPreDraw();
};

#endif /* ImageViewRenderer_hpp */
