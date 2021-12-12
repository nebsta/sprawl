//
//  BoardContext.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 30/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef BoardContext_hpp
#define BoardContext_hpp

#include "Context.hpp"
#include "BoardView.hpp"

#include "BlueprintManager.hpp"
#include "BoardInputView.hpp"

class BoardContext : public Context {
public:
    BoardContext();
    ~BoardContext();
    
    void init();
    void initWithView(View *view);
    
private:;
    BoardDataModel *_boardDataModel;
    
    BoardView *_boardView;
    BoardInputView *_boardInputView;
};

#endif /* BoardContext_hpp */
