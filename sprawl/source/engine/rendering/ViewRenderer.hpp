//
//  ViewRenderer.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 3/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef ViewRenderer_hpp
#define ViewRenderer_hpp

#define VIEW_RENDERER_DEFAULT_COLOR COLOR_WHITE
#define VIEW_RENDERER_DEFAULT_MESH Square

#include "Renderer.hpp"

class ViewRenderer : public Renderer {
public:
    ViewRenderer();
    ViewRenderer(glm::vec4 tint);
    ViewRenderer(Mesh mesh, glm::vec4 tint);
    ~ViewRenderer();
    
private:
    
};

#endif /* ViewRenderer_hpp */
