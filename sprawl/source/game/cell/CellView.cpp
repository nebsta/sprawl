//
//  CellView.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 9/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#include "CellView.hpp"

CellView::CellView(CellDataModel model, const SpriteLoader& spriteLoader) :
_dataModel(model)) {
    
    Sprite sprite = spriteForType(spriteLoader, model.type);
    _imageView = ImageView(sprite);
    
    _imageView.transform().setSize(glm::vec2(50,50));
    addChild(_imageView);
}

CellView::~CellView() {
}

#pragma mark Getters

CellDataModel CellView::dataModel() {
    return _dataModel;
}

void CellView::setTintColor(glm::vec4 tintColor) {
    _imageView.renderer().setTint(tintColor);
}
