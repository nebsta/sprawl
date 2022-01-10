//
//  CellView.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 9/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef CellView_hpp
#define CellView_hpp

#include "ImageView.hpp"
#include "CellDataModel.h"
#include "SpriteManager.hpp"

class CellView : public View {
    
public:
    CellView(const CellDataModel& model, const SpriteManager& spriteManager);
    ~CellView();
};

#endif /* CellView_hpp */
