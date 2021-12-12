//
//  BlueprintManager.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 30/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef BlueprintManager_hpp
#define BlueprintManager_hpp

#import <Foundation/Foundation.h>

#include "Object.hpp"
#include "BlueprintDataModel.h"
#include "Logger.h"

class BlueprintManager : public Object {
public:
    BlueprintManager();
    
    BlueprintDataModel getRandomBlueprint();
    
private:
    std::vector<BlueprintDataModel> _allBlueprints;
    
    CellType typeForIndex(int index);
    
    void parseBlueprint(std::string filename);
    CellType cellTypeForOrdinal(int ordinal);
};

#endif /* BlueprintManager_hpp */
