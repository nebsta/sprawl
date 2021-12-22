//
//  Renderer.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 8/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Renderer.hpp"

typedef std::vector<Renderer*>::iterator RendererIterator;

Renderer::Renderer() : Renderer(RENDERER_DEFAULT_SHAPE,RENDERER_DEFAULT_COLOR) {
    
}

Renderer::Renderer(const glm::vec4& tint) : Renderer(RENDERER_DEFAULT_SHAPE,tint) {
    
}

Renderer::Renderer(const Mesh& mesh, const glm::vec4& tint) : Renderer(RENDERER_DEFAULT_SHAPE,RENDERER_DEFAULT_COLOR,RENDERER_DEFAULT_SHADER) {
    
}

Renderer::Renderer(const Mesh& mesh, const glm::vec4& tint, const std::string& shader) :
_vertexArray(0),
_vertexBuffer(0),
_mesh(mesh),
_tint(tint),
_modelviewMatrix(glm::mat4()),
_projectionMatrix(RENDERER_DEFAULT_PROJECTION),
_shader(shader),
_clipChildren(true) {
    
    _shaderProgram = ShaderManager::instance().getProgram(_shader);
    _tintId = ShaderManager::instance().getUniformId(_shader,Uniform_ColorTint);
    _modelviewId = ShaderManager::instance().getUniformId(_shader,Uniform_ModelviewMatrix);
    _projectionId = ShaderManager::instance().getUniformId(_shader,Uniform_ProjectionMatrix);
}

Renderer::~Renderer() {
    glDeleteBuffers(1, &_vertexBuffer);
    glDeleteVertexArraysOES(1, &_vertexArray);
}

void Renderer::render() {
    
    glUseProgram(_shaderProgram);

    glBindVertexArrayOES(_vertexArray);

    glUniform4fv(_tintId, 1, &_tint[0]);
    glUniformMatrix4fv(_modelviewId, 1, 0, &_modelviewMatrix[0][0]);
    glUniformMatrix4fv(_projectionId, 1, 0, &_projectionMatrix[0][0]);
    
    onPreDraw();

    glDrawArrays(GL_TRIANGLE_STRIP, 0, _mesh.vertexCount);
    glBindVertexArrayOES(0);

    onPostDraw();
}

#pragma mark Clipping

void Renderer::pushClippingRect() {
    if (!_clipChildren) {
        return;
    }
    
    // save a copy of the current clipping plan and applying our own clipping
    glGetIntegerv(GL_SCISSOR_BOX, _parentScissorRect);
    glScissor(_clippingRect.x, _clippingRect.y, _clippingRect.z, _clippingRect.w);
}

void Renderer::popClippingRect() {
    if (!_clipChildren) {
        return;
    }
    
    glScissor(_parentScissorRect[0], _parentScissorRect[1], _parentScissorRect[2], _parentScissorRect[3]);
}

#pragma mark Setters

void Renderer::setModelviewMatrix(const glm::mat4& matrix) {
    _modelviewMatrix = matrix;
}

void Renderer::setProjectionMatrix(const glm::mat4& matrix) {
    _projectionMatrix = matrix;
}

void Renderer::setTint(const glm::vec4& tint) {
    _tint = tint;
}

void Renderer::setClippingRect(const glm::vec4& clippingRect) {
    _clippingRect = clippingRect;
}

void Renderer::setClipChildren(const bool& clipChildren) {
    _clipChildren = clipChildren;
}

#pragma mark Virtual Functions

void Renderer::onPreDraw() {
    
}

void Renderer::onPostDraw() {
    
}
