//
//  BoardView.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 3/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef BoardRenderer_hpp
#define BoardRenderer_hpp

#include <vector>

#include "SpriteManager.h"
#include "MathConstants.h"
#include "BoardDataModel.hpp"
#include "BoardLayerView.hpp"

#include "MessageManager.hpp"

#define BOARDVIEW_DEFAULT_SIZE glm::vec2(300,550)

typedef enum BoardLayer {
    Boardlayer_Blueprint,
    BoardLayer_Blocks
} BoardLayer;

class BoardView : public View, public BoardDataModelListener {
    
public:
    BoardView();
    ~BoardView();
    
    void addCell(CellDataModel cell, BoardLayer layer);
    void removeCell(CellDataModel cell, BoardLayer layer);
    
    void onCellAdded(CellDataModel cell);
    void onCellRemoved(GridLocation location);
    void onBlueprintAdded(GridLocation origin, BlueprintDataModel blueprint);
    
private:
    std::map<int,BoardLayerView*> _layers;
};

#endif /* BoardRenderer_hpp */
