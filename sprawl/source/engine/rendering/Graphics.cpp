//
//  Graphics.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#include "Graphics.hpp"

Renderer* Graphics::CreateViewRenderer(const glm::vec4& tint) {
#ifdef GRAPHICS_OPENGL
    return new OGLViewRenderer(tint);
#else
    return new MetalViewRenderer();
#endif
}

Renderer* Graphics::CreateImageRenderer(const Sprite& sprite, const glm::vec4& tint) {
#ifdef GRAPHICS_OPENGL
    return new OGLImageViewRenderer(sprite, tint);
#else
    return new MetalImageViewRenderer();
#endif
}
