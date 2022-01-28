//
//  OGLViewRenderer.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#ifndef OGLViewRenderer_hpp
#define OGLViewRenderer_hpp

#include <stdio.h>

#include "OGLRenderer.hpp"

class OGLViewRenderer : public OGLRenderer {
public:
    OGLViewRenderer();
    OGLViewRenderer(const glm::vec4& tint);
    OGLViewRenderer(const Mesh& mesh, const glm::vec4& tint);
    
    ~OGLViewRenderer();
private:
};

#endif /* OGLViewRenderer_hpp */
