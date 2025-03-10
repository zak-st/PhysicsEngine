#include "Renderer.h"
#include <iostream>

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
    delete testSprite;
}

void Renderer::Init() {
    glViewport(0, 0, 800, 600);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    shader = new Shader("vertexShader.glsl", "fragmentShader.glsl");
    testSprite = new Sprite(0.5f, 0.5f, *shader);
}


void Renderer::Render() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    testSprite->Render();
}