#version 330 core

in vec2 TexCoord;  // From vertex shader
out vec4 FragColor; // Final pixel color

uniform sampler2D spriteTexture;  // Texture unit
uniform vec4 spriteColor;  // Color multiplier (for tinting)

void main() {
    FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
