//
//  BlueprintDataModel.h
//  sprawl
//
//  Created by Benjamin Wallis on 10/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef BlueprintDataModel_h
#define BlueprintDataModel_h

#include <vector>
#include <glm.hpp>

#include "CellDataModel.h"

typedef struct BlueprintDataModel {
    int width;
    int height;
    
    std::vector<CellDataModel> cells;
} BlueprintDataModel;

#endif /* BlueprintDataModel_h */
