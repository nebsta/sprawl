//
//  ImageViewShader.fsh
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

varying lowp vec4 colorVarying;
varying lowp vec2 textCoordVarying;

uniform sampler2D texture;

void main()
{
    if (colorVarying.a < 0.5) {
        discard;
    } else {
        gl_FragColor = colorVarying * texture2D(texture, textCoordVarying);
    }
}
