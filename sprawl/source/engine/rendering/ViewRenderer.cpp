//
//  ViewRenderer.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 3/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#include "ViewRenderer.hpp"

ViewRenderer::ViewRenderer() : ViewRenderer(VIEW_RENDERER_DEFAULT_COLOR) {
    
}

ViewRenderer::ViewRenderer(const glm::vec4& tint) : ViewRenderer(VIEW_RENDERER_DEFAULT_MESH,tint) {
    
}

ViewRenderer::ViewRenderer(const Mesh& mesh, const glm::vec4& tint) : Renderer(mesh, tint) {
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

ViewRenderer::~ViewRenderer() {
    
}
