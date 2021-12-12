//
//  BoardManager.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef BoardManager_hpp
#define BoardManager_hpp

#include <stdio.h>

#include "BoardDataModel.hpp"
#include "BoardView.hpp"
#include "ImageView.hpp"

class BoardManager {
    
public:
    static BoardManager& instance() {
        static BoardManager instance;
        return instance;
    }
    
    void initialize();
    void teardown();
    
    BoardView* boardView();
    
private:
    BoardDataModel *_dataModel;
    BoardView *_boardView;
};

#endif /* BoardManager_hpp */
