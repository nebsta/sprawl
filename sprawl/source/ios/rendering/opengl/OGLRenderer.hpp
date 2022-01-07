//
//  OpenGLRenderer.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#ifndef OpenGLRenderer_hpp
#define OpenGLRenderer_hpp

#include <stdio.h>
#import "Renderer.hpp"

class OGLRenderer : public Renderer {
public:
    OGLRenderer();
    OGLRenderer(const glm::vec4& tint);
    OGLRenderer(const Mesh& mesh, const glm::vec4& tint);
    OGLRenderer(const Mesh& mesh, const glm::vec4& tint, const std::string& shader);
    ~OGLRenderer();
    
private:
    GLuint _shaderProgram;
    GLuint _tintId;
    GLuint _modelviewId;
    GLuint _projectionId;
    
protected:
    GLuint _vertexArray;
    GLuint _vertexBuffer;
    
    void preDraw();
    void draw();
};

#endif /* OpenGLRenderer_hpp */
