//
//  ImageViewShader.vsh
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

attribute vec2 position;

varying lowp vec4 colorVarying;

uniform vec4 colorTint;
uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;

void main()
{
    colorVarying = colorTint;
    gl_Position = projectionMatrix * modelViewMatrix * vec4(position.x, position.y,0,1);
}
