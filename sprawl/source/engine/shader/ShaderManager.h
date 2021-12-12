//
//  ShaderManager.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef ShaderManager_hpp
#define ShaderManager_hpp

#import <GLKit/GLKit.h>
#import <OpenGLES/ES2/glext.h>
#import <Foundation/Foundation.h>

#include <stdio.h>
#include <string>
#include <map>

#include "Logger.h"

using namespace std;


typedef enum Attribute {
    Attribute_Position = 0,
    Attribute_TextCoord = 1
} Attributes;

typedef enum Uniform {
    Uniform_ProjectionMatrix = 0,
    Uniform_ModelviewMatrix = 1,
    Uniform_ColorTint = 2
} Uniforms;

class ShaderManager {
    
public:
    static ShaderManager& instance() {
        static ShaderManager instance;
        return instance;
    }
    
    void initialize();
    void teardown();
    
    GLuint getProgram(string name);
    GLuint getUniformId(std::string shader, Uniform uniform);
    GLuint getUniformId(Uniform uniform);
    
private:
    NSMutableDictionary *_uniforms;
    string _currentShader;
    map<string,GLuint> _allPrograms;
    
    bool loadShader(NSString *name, NSDictionary *attrs, NSDictionary *uniforms);
    bool compileShader(GLuint* shader, GLenum type, NSString *filename);
    bool linkProgram(GLuint program);
    bool validateProgram(GLuint program);
};

#endif /* ShaderManager_hpp */
