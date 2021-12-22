//
//  ImageViewRenderer.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 8/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "ImageViewRenderer.hpp"

ImageViewRenderer::ImageViewRenderer() : ImageViewRenderer(IMAGEVIEW_RENDERER_DEFAULT_SHAPE) {
    
}

ImageViewRenderer::ImageViewRenderer(const Mesh& shape) : ImageViewRenderer(shape,IMAGEVIEW_RENDERER_DEFAULT_SPRITE) {
    
}

ImageViewRenderer::ImageViewRenderer(const Sprite& sprite) : ImageViewRenderer(IMAGEVIEW_RENDERER_DEFAULT_SHAPE,sprite) {
    
}

ImageViewRenderer::ImageViewRenderer(const Mesh& shape, const Sprite& sprite) : ImageViewRenderer(shape,sprite,IMAGEVIEW_RENDERER_DEFAULT_COLOR) {
    
}

ImageViewRenderer::ImageViewRenderer(const Mesh& shape, const Sprite& sprite, const glm::vec4& tint) : Renderer(shape,tint,IMAGEVIEW_RENDERER_DEFAULT_SHADER),
_sprite(sprite) {
    
    refreshTextureCoords();
    
    glGenVertexArraysOES(1, &_vertexArray);
    glBindVertexArrayOES(_vertexArray);
    
    glGenBuffers(1, &_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*_mesh.vertexCount, _mesh.vertices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(Attribute_Position);
    glVertexAttribPointer(Attribute_Position, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(0));
    
    glEnableVertexAttribArray(Attribute_TextCoord);
    glVertexAttribPointer(Attribute_TextCoord, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(sizeof(glm::vec2)));
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArrayOES(0);
}

ImageViewRenderer::~ImageViewRenderer() {
    
}

void ImageViewRenderer::onPreDraw() {
    if (!isSpriteEmpty(_sprite)) {
        glBindTexture(GL_TEXTURE_2D, _sprite.texture.name);
    } else {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

void ImageViewRenderer::refreshTextureCoords() {
    if (isSpriteEmpty(_sprite)) {
        _mesh.vertices[0].textCoord = glm::vec2(0,0);
        _mesh.vertices[1].textCoord = glm::vec2(0,1);
        _mesh.vertices[2].textCoord = glm::vec2(1,0);
        _mesh.vertices[3].textCoord = glm::vec2(1,1);
        return;
    }
    
    Region region = _sprite.textureRegion;
    _mesh.vertices[0].textCoord = glm::vec2(region.x,region.y+region.h);
    _mesh.vertices[1].textCoord = glm::vec2(region.x,region.y);
    _mesh.vertices[2].textCoord = glm::vec2(region.x+region.w,region.y+region.h);
    _mesh.vertices[3].textCoord = glm::vec2(region.x+region.w,region.y);
}

void ImageViewRenderer::setSprite(Sprite sprite) {
    _sprite = sprite;
    refreshTextureCoords();
}
