// Copyright (C) 2015 by James M. Van Verth and Lars M. Bishop.
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

uniform mat4 IvModelViewProjectionMatrix;

layout(location = COLOR) in vec4 inColor;
layout(location = POSITION) in vec4 position;
layout(location = TEXCOORD0) in vec2 texCoord0;

void main()
{
    gl_Position = IvModelViewProjectionMatrix * position;
}
