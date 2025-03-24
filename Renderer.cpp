#include "Renderer.h"
#include <iostream>

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
    delete shader;
}

void Renderer::Init() {
    //resize rendering viewport
    glViewport(0, 0, 1600, 1600);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    shader = new Shader("defaultVertex.glsl", "defaultFragment.glsl");
    //testSprite = new Sprite(0.4f, 0.8f); 
}


void Renderer::Render() 
{
    shader = new Shader("defaultVertex.glsl", "defaultFragment.glsl");

    if (!shader) {
        std::cerr << "ERROR: Shader failed to initialize in Renderer!" << std::endl;
        return;
    }

    //std::cout << "Renderer Initialized with Shader!" << std::endl;
}

Shader* Renderer::GetShader()
{
    return shader;
}