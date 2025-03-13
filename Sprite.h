#pragma once
#include <GL/glew.h>

#include "Shader.h"
class Sprite
{
public:
	Sprite(float width, float height);
	Sprite(float width, float height, Shader& shader);
	~Sprite();
	
	void Render();

	Shader* GetShader();

private:
	GLuint VAO, VBO, EBO, textureID;
	Shader* shader;
	Shader* default_shader = nullptr;
	float width, height;
	void Init();
};