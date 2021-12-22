//
//  ImageView.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 6/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "ImageView.hpp"

ImageView::ImageView() : ImageView(SpriteEmpty) {
    
}

ImageView::ImageView(const Sprite& sprite) : ImageView(sprite,IMAGEVIEW_DEFAULT_POSITION) {
    
}

ImageView::ImageView(const Sprite& sprite, const glm::vec2& position) : ImageView(sprite,position,glm::vec2(sprite.texture.width,sprite.texture.height)) {
    
}

ImageView::ImageView(const Sprite& sprite, const glm::vec2& position, const glm::vec2& size) : View(position, size, new ImageViewRenderer(sprite)) {
    
}

ImageView::~ImageView() {
    
}

#pragma mark Setters

void ImageView::setSprite(Sprite sprite) {
    ImageViewRenderer renderer = (ImageViewRenderer&)_renderer;
    renderer.setSprite(sprite);
    
}
