#include "Collider.h"
#include "Player.h"
#include <iostream>
Collider::Collider(float width, float height) : size(width, height), offset(0.0f, 0.0f), position(0.0f, 0.0f)
{

}
Collider::~Collider()
{

}

float Collider::GetLeft() const
{
	return position.x - size.x / 2.0f + offset.x;
}
float Collider::GetRight() const
{
	return position.x + size.x / 2.0f + offset.x;
}
float Collider::GetTop() const
{
	return position.y + size.y / 2.0f + offset.y;
}
float Collider::GetBottom() const
{
	return position.y - size.y / 2.0f + offset.y;
}

void Collider::SetSize(float width, float height)
{
	size.x = width;
	size.y = height;
}
void Collider::SetOffset(float x, float y)
{
	offset.x = x;
	offset.y = y;
}

void Collider::Update(const glm::vec2& object_pos)
{
	position = object_pos + offset;
}

void Collider::GetVertices(float* outVertices) const
{
    float left = GetLeft();
    float right = GetRight();
    float top = GetTop();
    float bottom = GetBottom();

	outVertices[0] = left;  outVertices[1] = top;
	outVertices[2] = right; outVertices[3] = top;
	outVertices[4] = right; outVertices[5] = bottom;
	outVertices[6] = left;  outVertices[7] = bottom;
}