#pragma once
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Collider
{
public:
	Collider(float width, float height);
	~Collider();

	float GetLeft() const;
	float GetRight() const;
	float GetTop() const;
	float GetBottom() const;

	void SetSize(float width, float height);
	void SetOffset(float x, float y);

	void Update(const glm::vec2& object_pos);

	void GetVertices(float* outVertices) const;


private:
	glm::vec2 offset;
	glm::vec2 size;
	glm::vec2 position;

};
