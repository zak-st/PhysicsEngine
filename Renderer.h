#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Sprite.h"
#include "Shader.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void Init();
    void Render();

    Shader* GetShader();

private:
    Shader* shader;
};