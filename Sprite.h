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

	void SetPosition(float x, float y);

private:
	GLuint VAO, VBO, EBO, textureID;
	Shader* shader;
	Shader* default_shader = nullptr;
	float width, height;
	float posX, posY;
	void Init();
};