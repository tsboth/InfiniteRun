#version 150

out vec4 FragColor;

in vec2 uv;

void main() {
    float pct;

    pct = log(distance(uv, vec2(0.5)) * 6);
    vec4 color = vec4(0.0, 0.0, 1 - pct, pct);

    FragColor = 1 - color;
}
