#version 300 es

in mediump vec3 colorOut;
out mediump vec4 fragColor;

void main() {
    fragColor = vec4(colorOut,1.0f);
}