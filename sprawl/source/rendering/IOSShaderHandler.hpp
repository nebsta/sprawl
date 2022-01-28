//
//  IOSShaderHandler.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 13/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#ifndef IOSShaderHandler_hpp
#define IOSShaderHandler_hpp

#include <stdio.h>

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

#endif /* IOSShaderHandler_hpp */
