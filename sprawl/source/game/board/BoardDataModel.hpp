//
//  BoardDataModel.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef BoardDataModel_hpp
#define BoardDataModel_hpp

#include <stdio.h>
#include <glm.hpp>
#include <map>

#include "CellDataModel.h"
#include "BlueprintDataModel.h"
#include "Object.hpp"

#define BOARD_DEFAULT_GRID_SIZE glm::vec2(6,11)
#define BOARD_DEFAULT_CELL_SIZE glm::vec2(50,50)

class BoardDataModelListener {
public:
    virtual void onCellAdded(const CellDataModel& cell) = 0;
    virtual void onCellRemoved(const GridLocation& location) = 0;
    virtual void onBlueprintAdded(const GridLocation& origin, const BlueprintDataModel& blueprint) = 0;
};

class BoardDataModel : public Object {
    
public:
    BoardDataModel();
    BoardDataModel(glm::vec2 gridSize, glm::vec2 cellSize);
    ~BoardDataModel();
    
    glm::vec2 gridSize();
    glm::vec2 cellSize();
    std::map<int,CellDataModel> cells();
    
    bool buildCellExists(GridLocation location);
    bool blueprintCellExists(GridLocation location);
    
    CellDataModel buildCellAt(GridLocation location);
    CellDataModel blueprintCellAt(GridLocation location);
    
    void addBuildCell(CellDataModel cell);
    void removeBuildCell(GridLocation location);
    
    void addBlueprint(BlueprintDataModel blueprint);
    
    void setListener(BoardDataModelListener *listener);
    
private:
    glm::vec2 _gridSize;
    glm::vec2 _cellSize;
    std::map<int,CellDataModel> _cells;
    std::map<int,CellDataModel> _blueprint;
    
    BoardDataModelListener *_listener;
    
    int indexForLocation(GridLocation location);
};

#endif /* BoardDataModel_hpp */
