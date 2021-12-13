//
//  BoardLayerView.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 30/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#include "BoardLayerView.hpp"

BoardLayerView::BoardLayerView(glm::vec2 size, const SpriteLoader& spriteLoader) : View(VECTOR_EMPTY,size,COLOR_CLEAR),
_spriteLoader(spriteLoader) {
    
}

BoardLayerView::~BoardLayerView() {
    
}

void BoardLayerView::addCell(CellDataModel cell) {
    CellView view = CellView(cell, _spriteLoader);
    view.transform().setLocalPosition(glm::vec2(cell.location.column*50,cell.location.row*50));
    view.transform().setSize(glm::vec2(50,50));
    addChild(&view);
}

void BoardLayerView::removeCell(CellDataModel cell) {
    
}
