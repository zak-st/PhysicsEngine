#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Sprite.h"
#include "Shader.h"
#include "GameObjectManager.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void Init();
    void Render();
    void DebugDraw(const GameObjectManager& obj_manager);
	void SetDebugDraw(bool debug) {
		debug_draw = debug;
	}
	void DrawLines(const float* vertices, int points);
	void SetProjection(int w, int h);
	bool GetDebugDraw() const { return debug_draw; }

    Shader* GetShader();
	Shader* GetDebugShader();

private:
    Shader* shader;
	Shader* debug_shader;
	bool debug_draw = true;
	glm::mat4 projection;
};