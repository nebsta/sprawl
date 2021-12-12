//
//  BoardDataModel.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 9/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#include "BoardDataModel.hpp"

typedef std::map<int,CellDataModel>::iterator CellIterator;

BoardDataModel::BoardDataModel() : BoardDataModel(BOARD_DEFAULT_GRID_SIZE, BOARD_DEFAULT_CELL_SIZE) {
    
}

BoardDataModel::BoardDataModel(glm::vec2 gridSize, glm::vec2 cellSize) :
_gridSize(gridSize),
_cellSize(cellSize) {
    
}

BoardDataModel::~BoardDataModel() {
    _cells.clear();
    _blueprint.clear();
}

#pragma mark Querying

void BoardDataModel::addBuildCell(CellDataModel cell) {
    int index = indexForLocation(cell.location);
    if (_cells.find(index) != _cells.end()) {
        return;
    }
    _cells[index] = cell;
    
    if (_listener != nullptr) {
        _listener->onCellAdded(cell);
    }
}

void BoardDataModel::removeBuildCell(GridLocation location) {
    int index = indexForLocation(location);
    CellIterator pos = _cells.find(index);
    if (pos == _cells.end()) {
        return;
    }
    _cells.erase(pos);
    
    if (_listener != nullptr) {
        _listener->onCellRemoved(location);
    }
}

void BoardDataModel::addBlueprint(BlueprintDataModel blueprint) {
    int originColumn = (_gridSize.x - blueprint.width) / 2;
    int originRow = (_gridSize.y - blueprint.height);
    GridLocation location = {originColumn, originRow};
    
    if (_listener != nullptr) {
        _listener->onBlueprintAdded(location,blueprint);
    }
}

bool BoardDataModel::buildCellExists(GridLocation location) {
    return !isEmptyCell(buildCellAt(location));
}

bool BoardDataModel::blueprintCellExists(GridLocation location) {
    return !isEmptyCell(blueprintCellAt(location));
}

CellDataModel BoardDataModel::buildCellAt(GridLocation location) {
    int index = indexForLocation(location);
    if (index >= _cells.size()) {
        return CELL_EMPTY;
    }
    return _cells[index];
}

CellDataModel BoardDataModel::blueprintCellAt(GridLocation location) {
    int index = indexForLocation(location);
    if (index >= _blueprint.size()) {
        return CELL_EMPTY;
    }
    return _blueprint[index];
}

int BoardDataModel::indexForLocation(GridLocation location) {
    return (_gridSize.x * location.row) + location.column;
}

#pragma mark Getters

glm::vec2 BoardDataModel::gridSize() {
    return _gridSize;
}

glm::vec2 BoardDataModel::cellSize() {
    return _cellSize;
}

std::map<int,CellDataModel> BoardDataModel::cells() {
    return _cells;
}

#pragma mark Setters

void BoardDataModel::setListener(BoardDataModelListener *listener) {
    _listener = listener;
}
