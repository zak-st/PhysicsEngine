#version 330 core

layout (location = 0) in vec3 aPos;      // Vertex position (x, y, z)
layout (location = 1) in vec2 aTexCoord; // Texture coordinates (u, v)

out vec2 TexCoord;  // Pass to fragment shader

uniform mat4 model;  // Object transformation matrix
uniform mat4 projection; // Projection matrix (camera/viewport)

void main() {
    gl_Position = projection * model * vec4(aPos, 1.0);
}
