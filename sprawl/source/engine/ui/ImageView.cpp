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

ImageView::ImageView(Sprite sprite) : ImageView(sprite,IMAGEVIEW_DEFAULT_POSITION) {
    
}

ImageView::ImageView(Sprite sprite, glm::vec2 position) : ImageView(sprite,position,glm::vec2(sprite.texture.width,sprite.texture.height)) {
    
}

ImageView::ImageView(Sprite sprite, glm::vec2 position, glm::vec2 size) :
View(position,size,IMAGEVIEW_DEFAULT_COLOR, ImageViewRenderer(sprite)) {
    
}

ImageView::~ImageView() {
    
}

#pragma mark Setters

void ImageView::setSprite(Sprite sprite) {
    
    ImageViewRenderer renderer = (ImageViewRenderer)_renderer;
    renderer.setSprite(sprite);
    
}
