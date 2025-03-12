#include <iostream>

#include "Sprite.h"


Sprite::Sprite(float width, float height) : width(width), height(height), posX(0.0f), posY(0.0f)
{
    default_shader = new Shader("defaultVertex.glsl", "defaultFragment.glsl");
    shader = default_shader;
    Init();
    Init();
}

Sprite::Sprite(float width, float height, Shader& shader) : width(width), height(height), shader(&shader), posX(0.0f), posY(0.0f)
{
	Init();
}

Sprite::~Sprite()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
    if (default_shader) {
        delete default_shader;
    }
}

void Sprite::Init() {
    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;

    float vertices[] = {
        // Positions (x, y, z)
        -halfWidth, -halfHeight, 0.0f,  // Bottom-left
         halfWidth, -halfHeight, 0.0f,  // Bottom-right
         halfWidth,  halfHeight, 0.0f,  // Top-right
        -halfWidth,  halfHeight, 0.0f   // Top-left
    };

    unsigned int indices[] = {
        0, 1, 2,  // First Triangle
        2, 3, 0   // Second Triangle
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Sprite::Render() {
    if (!shader) {
        std::cerr << "ERROR: Sprite shader is nullptr!" << std::endl;
        return;
    }

    shader->Use();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(posX, posY, 0.0f));

    glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    shader->SetMatrix4("model", model);
    shader->SetMatrix4("projection", projection);

    shader->SetVector4f("spriteColor", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));


    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    //std::cout << "Rendering sprite at: " << posX << ", " << posY << std::endl;
}

void Sprite::SetPosition(float x, float y)
{
    posX = x;
    posY = y;
}