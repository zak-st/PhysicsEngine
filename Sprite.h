#pragma once
#include <GL/glew.h>

#include "Shader.h"
class Sprite
{
public:
	Sprite(float width, float height, Shader& shader);
	~Sprite();
	
	void Render();

private:
	GLuint VAO, VBO, EBO;
	Shader& shader;
	float width, height;
	void Init();
};