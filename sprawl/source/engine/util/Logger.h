//
//  Logger.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef Logger_hpp
#define Logger_hpp

#include <string>
#include <sstream>
#include <iostream>

class Logger {
    
public:
    static void logMessage(std::string message);
    static void logMessage(std::string message, const char* vs...);
    static void logError(std::string message);
    
};

#endif /* Logger_hpp */
