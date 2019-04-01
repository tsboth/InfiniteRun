// Copyright (C) 2015 by James M. Van Verth and Lars M. Bishop.
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#version 150

uniform sampler2D Texture;
uniform float speed;

in vec2 uv;
in vec4 color;

out vec4 fragColor;

void main()
{
    fragColor = texture(Texture, fract(vec2(uv.x + speed, uv.y)));
}
