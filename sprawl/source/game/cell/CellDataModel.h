//
//  CellDataModel.h
//  sprawl
//
//  Created by Benjamin Wallis on 9/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef CellDataModel_h
#define CellDataModel_h

#include <string>

#include "SpriteManager.hpp"
#include "MathConstants.h"

#define GLOCATION_EMPTY (GridLocation){-1,-1}
#define CELL_EMPTY {Cell_None,GLOCATION_EMPTY}

typedef enum CellType {
    Cell_None,
    Cell_Wall,
    Cell_Door,
    Cell_Window,
    Cell_Roof
} CellType;

typedef struct GridLocation {
    int column; int row;
    
    GridLocation& operator+=(const GridLocation& s2) {
        column += s2.column;
        row += s2.row;
        return (*this);
    }
} GridLocation;

typedef struct CellDataModel {
    CellType type;
    GridLocation location;
} CellDataModel;

inline std::string spriteNameForType(CellType type) {
    std::string name;
    switch(type) {
        case Cell_None: name = ""; break;
        case Cell_Wall: name = "cell_wall"; break;
        case Cell_Door: name = "cell_door"; break;
        case Cell_Window: name = "cell_window"; break;
        case Cell_Roof: name = ""; break;
    }
    return name;
}

inline Sprite spriteForType(const SpriteManager& manager, CellType type) {
    if (type == Cell_None) {
        return SpriteEmpty;
    }
    
    std::string name = spriteNameForType(type);
    return manager.loadSprite("main_tileset_hd",name);
}

inline bool operator==(const GridLocation& s1, const GridLocation& s2)
{
    return s1.row == s2.row && s1.column == s2.column;
}

inline GridLocation operator+(const GridLocation& s1, const GridLocation& s2) {
    return {s1.column+s2.column, s1.row + s2.row};
}

inline bool isEmptyGridLocation(GridLocation location) {
    return location == GLOCATION_EMPTY;
}

inline bool isEmptyCell(CellDataModel cell) {
    return cell.type == Cell_None && isEmptyGridLocation(cell.location);
}

#endif /* CellDataModel_h */
