//
//  ShaderManager.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "ShaderManager.h"

typedef map<string,GLuint>::iterator ProgramIterator;

void ShaderManager::initialize() {
    _uniforms = [[NSMutableDictionary alloc] init];

    NSString *path = [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:"shader_config"] ofType:@"plist"];
    NSArray *root = [NSArray arrayWithContentsOfFile:path];

    for (int i = 0; i < [root count]; i++) {
        NSDictionary *dict = root[i];
        loadShader(dict[@"name"], dict[@"attributes"], dict[@"uniforms"]);
    }
}

bool ShaderManager::loadShader(NSString *name, NSDictionary *attrs, NSDictionary *uniforms) {
    GLuint vertShader, fragShader;
    NSString *vertShaderPathname, *fragShaderPathname;

    // Create shader program.
    GLuint newProgram = glCreateProgram();

    // Create and compile vertex shader.
    vertShaderPathname = [[NSBundle mainBundle] pathForResource:name ofType:@"vsh"];
    if (!compileShader(&vertShader, GL_VERTEX_SHADER, vertShaderPathname)) {
        NSLog(@"Failed to compile vertex shader");
        return false;
    }

    // Create and compile fragment shader.
    fragShaderPathname = [[NSBundle mainBundle] pathForResource:name ofType:@"fsh"];
    if (!compileShader(&fragShader, GL_FRAGMENT_SHADER, fragShaderPathname)) {
        Logger::logError("Failed to compile fragment shader");
        return false;
    }

    // Attach vertex shader to program.
    glAttachShader(newProgram, vertShader);
    glAttachShader(newProgram, fragShader);

    // Bind attribute locations.
    for (NSString *key in attrs.keyEnumerator) {
        glBindAttribLocation(newProgram, [key intValue], [[attrs objectForKey:key] UTF8String]);
    }

    // Link program.
    if (!linkProgram(newProgram)) {
        Logger::logError("Failed to link program");

        if (vertShader) {
            glDeleteShader(vertShader);
            vertShader = 0;
        }
        if (fragShader) {
            glDeleteShader(fragShader);
            fragShader = 0;
        }
        if (newProgram) {
            glDeleteProgram(newProgram);
            newProgram = 0;
        }

        return false;
    }

    // Get uniform locations
    NSMutableDictionary *shaderUniforms = [[NSMutableDictionary alloc] init];
    [uniforms enumerateKeysAndObjectsUsingBlock:^(id key, id value, BOOL *stop) {
        NSNumber *shaderLocation = [NSNumber numberWithInt:glGetUniformLocation(newProgram, [value UTF8String])];
        [shaderUniforms setValue:shaderLocation forKey:key];
    }];
    [_uniforms setObject:shaderUniforms forKey:name];

    // Release vertex and fragment shaders.
    if (vertShader) {
        glDetachShader(newProgram, vertShader);
        glDeleteShader(vertShader);
    }
    if (fragShader) {
        glDetachShader(newProgram, fragShader);
        glDeleteShader(fragShader);
    }
    
    _allPrograms[name.UTF8String] = newProgram;

    return true;
}

void ShaderManager::teardown() {
    for (ProgramIterator iter = _allPrograms.begin(); iter != _allPrograms.end(); iter++) {
        glDeleteProgram(iter->second);
    }
}

GLuint ShaderManager::getUniformId(std::string shader, Uniform uniform) {
    NSString *shaderKey = [NSString stringWithUTF8String:shader.c_str()];
    NSString *uniformKey = [NSString stringWithFormat:@"%d",(int)uniform];
    NSDictionary *shaderUniforms = [_uniforms valueForKey:shaderKey];
    NSNumber *value = [shaderUniforms objectForKey:uniformKey];
    return [value intValue];
}

GLuint ShaderManager::getUniformId(Uniform uniform) {
    return getUniformId(_currentShader, uniform);
}

bool ShaderManager::compileShader(GLuint* shader, GLenum type, NSString* filename) {
    GLint status;
    const GLchar *source;

    source = (GLchar *)[[NSString stringWithContentsOfFile:filename encoding:NSUTF8StringEncoding error:nil] UTF8String];
    if (!source) {
        Logger::logError("Failed to load vertex shader");
        return false;
    }

    *shader = glCreateShader(type);
    glShaderSource(*shader, 1, &source, NULL);
    glCompileShader(*shader);

#if defined(DEBUG)
    GLint logLength;
    glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar *log = (GLchar *)malloc(logLength);
        glGetShaderInfoLog(*shader, logLength, &logLength, log);
        NSLog(@"Shader compile log:\n%s", log);
        free(log);
    }
#endif

    glGetShaderiv(*shader, GL_COMPILE_STATUS, &status);
    if (status == 0) {
        glDeleteShader(*shader);
        return false;
    }

    return true;
}

bool ShaderManager::linkProgram(GLuint program) {
    GLint status;
    glLinkProgram(program);

#if defined(DEBUG)
    GLint logLength;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar *log = (GLchar *)malloc(logLength);
        glGetProgramInfoLog(program, logLength, &logLength, log);
        NSLog(@"Program link log:\n%s", log);
        free(log);
    }
#endif

    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (status == 0) {
        return false;
    }

    return true;
}

bool ShaderManager::validateProgram(GLuint program) {
    GLint logLength, status;

    glValidateProgram(program);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar *log = (GLchar *)malloc(logLength);
        glGetProgramInfoLog(program, logLength, &logLength, log);
        NSLog(@"Program validate log:\n%s", log);
        free(log);
    }

    glGetProgramiv(program, GL_VALIDATE_STATUS, &status);
    if (status == 0) {
        return false;
    }

    return true;
}

GLuint ShaderManager::getProgram(string name) {
    return _allPrograms[name];
}
