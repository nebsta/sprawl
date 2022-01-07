//
//  Graphics.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#include "Graphics.hpp"

#define GRAPHICS_OPENGL

Renderer* Graphics::CreateViewRenderer(const glm::vec4& tint) {
#ifdef GRAPHICS_OPENGL
    return new OGLViewRenderer(tint);
#endif
}

Renderer* Graphics::CreateImageRenderer(const Sprite& sprite, const glm::vec4& tint) {
#ifdef GRAPHICS_OPENGL
    return new OGLImageViewRenderer(sprite, tint);
#endif
}
