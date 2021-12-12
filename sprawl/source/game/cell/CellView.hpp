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
#include "SpriteManager.h"

class CellView : public View {
    
public:
    CellView(CellDataModel model);
    ~CellView();
    
    CellDataModel dataModel();
    
    void setTintColor(glm::vec4 tintColor);
    
private:
    ImageView *_imageView;
    CellDataModel _dataModel;
};

#endif /* CellView_hpp */
