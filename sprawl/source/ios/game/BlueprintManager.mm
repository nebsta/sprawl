//
//  BlueprintManager.mm
//  sprawl
//
//  Created by Benjamin Wallis on 30/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#include "BlueprintManager.hpp"

BlueprintManager::BlueprintManager() {
    parseBlueprint("example_blueprint");
}

void BlueprintManager::parseBlueprint(std::string filename) {
    NSString *path = [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:filename.c_str()] ofType:@"json"];
    
    // Check for any errors in the parsing
    NSError *error;
    NSData *data = [NSData dataWithContentsOfFile:path];
    NSDictionary *root = [NSJSONSerialization JSONObjectWithData:data options:0 error:&error];
    if (error != NULL) {
        Logger::logError("Error with blueprint parsing.");
        NSLog(@"ERROR: %@", error.debugDescription);
        return;
    }
    
    // Determine the size of the blueprint
    BlueprintDataModel blueprint;
    blueprint.width = [[root objectForKey:@"width"] intValue];
    blueprint.height = [[root objectForKey:@"height"] intValue];
    
    // Parse the individual cells
    NSArray *layers = [root objectForKey:@"layers"];
    for (NSDictionary *dict in layers) {
        NSString *layerName = [dict objectForKey:@"type"];
        if ([layerName isEqual:@"tilelayer"]) {
            NSArray *cellData = [dict objectForKey:@"data"];
            for (int i = 0; i < cellData.count; i++) {
                int typeIndex = [[cellData objectAtIndex:i] intValue];
                int row = i / blueprint.width;
                int column = i % blueprint.width;
                
                if (typeIndex == 0) {
                    continue;
                }
                
                CellDataModel cell;
                cell.type = typeForIndex(typeIndex);
                cell.location = {column, row};
                blueprint.cells.push_back(cell);
            }
        }
    }
    
    _allBlueprints.push_back(blueprint);
}

CellType BlueprintManager::typeForIndex(int index) {
    CellType cellType = Cell_None;
    switch (index) {
        case 0:
            cellType = Cell_None;
            break;
            
        case 1:
            cellType = Cell_Door;
            break;
            
        case 2:
            cellType = Cell_Wall;
            break;
            
        case 3:
            cellType = Cell_Window;
    }
    return cellType;
}

BlueprintDataModel BlueprintManager::getRandomBlueprint() {
    return _allBlueprints[0];
}
