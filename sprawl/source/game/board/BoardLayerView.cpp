//
//  BoardLayerView.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 30/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#include "BoardLayerView.hpp"

BoardLayerView::BoardLayerView(const glm::vec2& size, const SpriteManager& spriteManager) : View(VECTOR_EMPTY,size,COLOR_CLEAR),
_spriteManager(spriteManager) {
    
}

BoardLayerView::~BoardLayerView() {
    
}

void BoardLayerView::addCell(const CellDataModel& cell) {
    CellView* view = new CellView(cell, _spriteManager);
    view->transform().setLocalPosition(glm::vec2(cell.location.column*50,cell.location.row*50));
    view->transform().setSize(glm::vec2(50,50));
    addChild(view);
}

void BoardLayerView::removeCell(const CellDataModel& cell) {
    
}
