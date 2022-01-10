//
//  Graphics.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#ifndef Graphics_hpp
#define Graphics_hpp

#include <stdio.h>

#include "Renderer.hpp"

#ifdef GRAPHICS_OPENGL
#include "OGLViewRenderer.hpp"
#include "OGLImageViewRenderer.hpp"
#else
#include "MetalViewRenderer.hpp"
#include "MetalImageViewRenderer.hpp"
#endif

class Graphics {
public:
    static void Setup();
    static Renderer* CreateViewRenderer(const glm::vec4& tint);
    static Renderer* CreateImageRenderer(const Sprite& sprite, const glm::vec4& tint);
    
};

#endif /* Graphics_hpp */
