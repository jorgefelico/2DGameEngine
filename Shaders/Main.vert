#version 300 es

in mediump vec3 vertexIn;
in mediump vec3 colorIn;
out mediump vec3 colorOut;
void main() {
    gl_Position = vec4(vertexIn,1.0);
    colorOut = colorIn;
}