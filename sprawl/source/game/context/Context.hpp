//
//  Context.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 30/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef Context_hpp
#define Context_hpp

#include "Object.hpp"
#include "View.hpp"

class Context : public Object {
public:
    Context();
    ~Context();
    
    void init();
    void initWithView(View *view);
};

#endif /* Context_hpp */
