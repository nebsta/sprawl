//
//  OpenGLRenderer.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#include "OGLRenderer.hpp"

OGLRenderer::OGLRenderer() : OGLRenderer(RENDERER_DEFAULT_COLOR) {
    
}

OGLRenderer::OGLRenderer(const glm::vec4& tint) : OGLRenderer(RENDERER_DEFAULT_SHAPE, tint) {
    
}

OGLRenderer::OGLRenderer(const Mesh& mesh, const glm::vec4& tint) : OGLRenderer(mesh, tint, RENDERER_DEFAULT_SHADER) {
    
}

OGLRenderer::OGLRenderer(const Mesh& mesh, const glm::vec4& tint, const std::string& shader) : Renderer(mesh, tint, shader),
_vertexArray(0),
_vertexBuffer(0) {
    
    _shaderProgram = ShaderManager::instance().getProgram(_shader);
    _tintId = ShaderManager::instance().getUniformId(_shader,Uniform_ColorTint);
    _modelviewId = ShaderManager::instance().getUniformId(_shader,Uniform_ModelviewMatrix);
    _projectionId = ShaderManager::instance().getUniformId(_shader,Uniform_ProjectionMatrix);
}

OGLRenderer::~OGLRenderer() {
    glDeleteBuffers(1, &_vertexBuffer);
    glDeleteVertexArraysOES(1, &_vertexArray);
}

void OGLRenderer::preDraw() {
    glUseProgram(_shaderProgram);

    glBindVertexArrayOES(_vertexArray);

    glUniform4fv(_tintId, 1, &_tint[0]);
    glUniformMatrix4fv(_modelviewId, 1, 0, &_modelviewMatrix[0][0]);
    glUniformMatrix4fv(_projectionId, 1, 0, &_projectionMatrix[0][0]);
}

void OGLRenderer::draw() {
    glDrawArrays(GL_TRIANGLE_STRIP, 0, _mesh.vertexCount);
    glBindVertexArrayOES(0);
}

#pragma mark Clipping

void OGLRenderer::pushClippingRect() {
    if (!_clipChildren) {
        return;
    }
    
    // save a copy of the current clipping plan and applying our own clipping
    glGetIntegerv(GL_SCISSOR_BOX, _parentScissorRect);
    glScissor(_clippingRect.x, _clippingRect.y, _clippingRect.z, _clippingRect.w);
}

void OGLRenderer::popClippingRect() {
    if (!_clipChildren) {
        return;
    }
    
    glScissor(_parentScissorRect[0], _parentScissorRect[1], _parentScissorRect[2], _parentScissorRect[3]);
}
