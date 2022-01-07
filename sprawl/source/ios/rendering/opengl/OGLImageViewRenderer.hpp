//
//  OGLImageViewRenderer.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#ifndef OGLImageViewRenderer_hpp
#define OGLImageViewRenderer_hpp

#include <stdio.h>

#include "OGLRenderer.hpp"
#include "Sprite.h"

#define IMAGEVIEW_RENDERER_DEFAULT_COLOR COLOR_WHITE
#define IMAGEVIEW_RENDERER_DEFAULT_SHAPE Square
#define IMAGEVIEW_RENDERER_DEFAULT_SPRITE SpriteEmpty
#define IMAGEVIEW_RENDERER_DEFAULT_SHADER "ImageViewShader"

class OGLImageViewRenderer : public OGLRenderer {
    
public:
    OGLImageViewRenderer();
    OGLImageViewRenderer(const Mesh& mesh);
    OGLImageViewRenderer(const Sprite& sprite);
    OGLImageViewRenderer(const Sprite& sprite, const glm::vec4& tint);
    OGLImageViewRenderer(const Mesh& mesh, const Sprite& sprite);
    OGLImageViewRenderer(const Mesh& mesh, const Sprite& sprite, const glm::vec4& tint);
    ~OGLImageViewRenderer();
    
    void refreshTextureCoords();
    
    void setSprite(Sprite sprite);
    
private:
    Sprite _sprite;
    
protected:
    void setupAttribPointers();
    void preDraw();
};

#endif /* OGLImageViewRenderer_hpp */
