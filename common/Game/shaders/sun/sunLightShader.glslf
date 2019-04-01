#version 150

out vec4 fragColor;

in vec2 uv;

uniform float xPosition;

vec4 makeCircle(float size, float x, float y) {
    vec3 pct;
    pct.x = log2(distance(uv, vec2(x + xPosition, y)) * size);
    pct.y = log2(distance(uv, vec2(x + xPosition, y)) * (size + 0.5));
    pct.z = log2(distance(uv, vec2(x + xPosition, y)) * (size + 0.7));

    if (pct.x > .5)
        pct.x = log((1 - pct.x) * 2.5);
    if (pct.y > .5)
        pct.y = log((1 - pct.y) * 2.5);
    if (pct.z > .5)
        pct.z = log((1 - pct.z) * 2.5);

    return vec4(vec3(pct.x, 1.0, 1.0) * vec3(1.0, pct.y, 1.0) * vec3(1.0, 1.0, pct.z), pct.x / 5);
}

void main() {
    fragColor = max(max(makeCircle(7.0, 0.2 + 6. * xPosition, 0.2), makeCircle(12.0, 0.335 + 3. * xPosition, 0.51)), makeCircle(20.0, 0.42 + xPosition, 0.7));
}

