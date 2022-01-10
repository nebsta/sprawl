//
//  BoardLayerView.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 30/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef BoardLayerView_hpp
#define BoardLayerView_hpp

#import "CellView.hpp"
#import "SpriteManager.hpp"

class BoardLayerView : public View {
public:
    BoardLayerView(const glm::vec2& size, const SpriteManager& spriteManager);
    ~BoardLayerView();
    
    void addCell(const CellDataModel& cell);
    void removeCell(const CellDataModel& cell);
    
private:
    const SpriteManager& _spriteManager;
};

#endif /* BoardLayerView_hpp */
