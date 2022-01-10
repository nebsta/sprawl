//
//  CellView.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 9/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#include "CellView.hpp"

CellView::CellView(const CellDataModel& model, const SpriteManager& spriteManager) {
    
    ImageView *imageView = new ImageView(spriteForType(spriteManager, model.type));
    imageView->transform().setSize(glm::vec2(50,50));
    addChild(imageView);
}

CellView::~CellView() {
}
