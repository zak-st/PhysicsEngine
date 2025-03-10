#include "Vector.h"
#include <iostream>

Vector::Vector() : x(0), y(0), z(1)
{

}
Vector::Vector(float x, float y) : x(x), y(y), z(1)
{

}
Vector::Vector(float x, float y, float z) : x(x), y(y), z(z)
{

}
Vector::~Vector()
{

}
Vector Vector::operator+(const Vector& other) const
{
	return Vector(x + other.x, y + other.y);
}
Vector Vector::operator-(const Vector& other) const
{
	return Vector(x - other.x, y - other.y);
}
Vector Vector::operator*(float scalar) const
{
	return Vector(x * scalar, y * scalar);
}
void Vector::Print() const
{
	std::cout << "(" << x << ", " << y << ", " << z << ")\n";
}