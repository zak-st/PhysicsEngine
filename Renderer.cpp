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
    projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    shader = new Shader("defaultVertex.glsl", "defaultFragment.glsl");
	debug_shader = new Shader("debugVertex.glsl", "debugFragment.glsl");
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
Shader* Renderer::GetDebugShader()
{
	return debug_shader;
}

void Renderer::SetProjection(int width, int height) {
    projection = glm::ortho(0.0f, static_cast<float>(width),
        0.0f, static_cast<float>(height),
        -1.0f, 1.0f);
}
void Renderer::DrawLines(const float* vertices, int points)
{
    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * points * 2, vertices, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_LINE_LOOP, 0, points);

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}
void Renderer::DebugDraw(const GameObjectManager& obj_manager)
{
    if (!debug_draw || !debug_shader) return;

    debug_shader->Use();
    debug_shader->SetMatrix4("projection", projection);
    debug_shader->SetVector4f("lineColor", glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
    const std::vector<GameObject*>& objects = obj_manager.GetObjects();
    for (GameObject* obj : objects) {
        if (obj && obj->GetCollider()) {
            float vertices[8];
            obj->GetCollider()->GetVertices(vertices);
            DrawLines(vertices, 4);
        }
    }
}