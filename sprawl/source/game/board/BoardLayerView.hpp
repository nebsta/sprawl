//
//  BoardLayerView.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 30/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef BoardLayerView_hpp
#define BoardLayerView_hpp

#define BLUEPRINT_COLOR glm::vec4(0.0f,0.0f,1.0f,1.0f)

#include "CellView.hpp"
#include "ImageView.hpp"

class BoardLayerView : public View {
public:
    BoardLayerView(glm::vec2 size, const SpriteLoader& spriteLoader);
    ~BoardLayerView();
    
    void addCell(CellDataModel cell);
    void removeCell(CellDataModel cell);
    
private:
    std::vector<ImageView*> _cellImages;
    const SpriteLoader& _spriteLoader;
};

#endif /* BoardLayerView_hpp */
