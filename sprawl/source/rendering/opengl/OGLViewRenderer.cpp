//
//  OGLViewRenderer.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#include "OGLViewRenderer.hpp"

OGLViewRenderer::OGLViewRenderer(const glm::vec4& tint) : OGLViewRenderer(RENDERER_DEFAULT_SHAPE, tint) {
    
}

OGLViewRenderer::OGLViewRenderer(const Mesh& mesh, const glm::vec4& tint) : OGLRenderer(mesh, tint) {
    glGenVertexArraysOES(1, &_vertexArray);
    glBindVertexArrayOES(_vertexArray);
    
    glGenBuffers(1, &_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*_mesh.vertexCount, _mesh.vertices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(Attribute_Position);
    glVertexAttribPointer(Attribute_Position, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(0));
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArrayOES(0);
}


OGLViewRenderer::~OGLViewRenderer() {
    
}
