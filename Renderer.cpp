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

    testSprite = new Sprite(0.4f, 0.8f); 
}


void Renderer::Render() 
{
    glClear(GL_COLOR_BUFFER_BIT);

    //std::cout << "Rendering frame..." << std::endl;

    if (!testSprite) {
        std::cerr << "ERROR: testSprite is nullptr!" << std::endl;
        return;
    }

    testSprite->Render();
}