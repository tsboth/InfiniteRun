// Copyright (C) 2015 by James M. Van Verth and Lars M. Bishop.
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#version 150
out vec4 fragColor;

uniform sampler2D Texture;

in vec2 uv;
in vec4 color;

void main()
{
    fragColor = texture(Texture, uv);
}
