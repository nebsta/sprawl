//
//  BoardView.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 3/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#include "BoardView.hpp"

BoardView::BoardView(BoardDataModel& model, const SpriteManager& spriteLoader) : View(VECTOR_EMPTY,BOARDVIEW_DEFAULT_SIZE)
{
    model.setListener(this);
    
    glm::vec2 size = transform().size();
    glm::vec2 boardPosition = glm::vec2((screenWidth()-size.x)*0.5f,screenHeight()-size.y);
    transform().setLocalPosition(boardPosition);
    
    buildLayerView(BoardLayer_Blocks, spriteLoader);
    buildLayerView(BoardLayer_Blueprint, spriteLoader);
    
//    View *animationTest = new View();
//    animationTest->transform()->setLocalPosition(glm::vec2(50,50));
//    animationTest->transform()->setSize(glm::vec2(30,30));
//    animationTest->renderer()->setTint(COLOR_RED);
//    addChild(animationTest);
  
//    animationTest->animator()->animateByPosition(glm::vec2(0,150))
//      ->setDuration(2.0f)
//      ->setAnimationCurve(CURVE_LINEAR)
//      ->setLoop(true)
//      ->play();
  
//    View *animationTest2 = new View();
//    animationTest2->transform()->setLocalPosition(glm::vec2(150,50));
//    animationTest2->transform()->setSize(glm::vec2(30,30));
//    animationTest2->renderer()->setTint(COLOR_BLUE);
//    addChild(animationTest2);
//    
//    View *animationTest3 = new View();
//    animationTest3->transform()->setLocalPosition(glm::vec2(250,50));
//    animationTest3->transform()->setSize(glm::vec2(30,30));
//    animationTest3->renderer()->setTint(COLOR_GREEN);
//    addChild(animationTest3);
//    
//    View *animationTest4 = new View();
//    animationTest4->transform()->setLocalPosition(glm::vec2(0,50));
//    animationTest4->transform()->setSize(glm::vec2(30,30));
//    animationTest4->renderer()->setTint(COLOR_BLACK);
//    addChild(animationTest4);
  
//    animationTest2->animator()->setStartPosition(animationTest2->transform()->localPosition());
//    animationTest2->animator()->setEndPosition(animationTest2->transform()->localPosition()+glm::vec2(0,150));
//    animationTest2->animator()->setStartSize(animationTest2->transform()->size());
//    animationTest2->animator()->setEndSize(animationTest2->transform()->size());
//    animationTest2->animator()->setDuration(2.0f);
//    animationTest2->animator()->setLoop(true);
//    animationTest2->animator()->setAnimationCurve(CURVE_EASE_IN);
//    animationTest2->animator()->play();
//    
//    animationTest3->animator()->setStartPosition(animationTest3->transform()->localPosition());
//    animationTest3->animator()->setEndPosition(animationTest3->transform()->localPosition()+glm::vec2(0,150));
//    animationTest3->animator()->setStartSize(animationTest3->transform()->size());
//    animationTest3->animator()->setEndSize(animationTest3->transform()->size());
//    animationTest3->animator()->setDuration(2.0f);
//    animationTest3->animator()->setLoop(true);
//    animationTest3->animator()->setAnimationCurve(CURVE_EASE_OUT);
//    animationTest3->animator()->play();
//    
//    animationTest4->animator()->setStartPosition(animationTest4->transform()->localPosition());
//    animationTest4->animator()->setEndPosition(animationTest4->transform()->localPosition()+glm::vec2(0,150));
//    animationTest4->animator()->setStartSize(animationTest4->transform()->size());
//    animationTest4->animator()->setEndSize(animationTest4->transform()->size());
//    animationTest4->animator()->setDuration(2.0f);
//    animationTest4->animator()->setLoop(true);
//    animationTest4->animator()->setAnimationCurve({0.7f, -1.11,0.46, 1.84});
//    animationTest4->animator()->play();
}

BoardView::~BoardView() {
    
}

void BoardView::buildLayerView(const BoardLayer &layer, const SpriteManager& spriteManager) {
    BoardLayerView *view = new BoardLayerView(transform().size(), spriteManager);
    addChild(view);
    _layers[layer] = view;
}

void BoardView::addCell(const CellDataModel& cell, const BoardLayer& layer) {
    _layers.at(layer)->addCell(cell);
}

void BoardView::removeCell(const CellDataModel& cell, const BoardLayer& layer) {
    
}

#pragma mark Events

void BoardView::onCellAdded(const CellDataModel& cell) {
    
}

void BoardView::onCellRemoved(const GridLocation& location) {
    
}

void BoardView::onBlueprintAdded(const GridLocation& origin, const BlueprintDataModel& blueprint) {
    
    std::vector<CellDataModel>::const_iterator iter = blueprint.cells.begin();
    for (; iter != blueprint.cells.end(); iter++) {
        CellDataModel cell = (*iter);
        cell.location += origin;
        addCell(cell, BoardLayer_Blueprint);
    }
}
