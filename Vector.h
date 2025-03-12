#pragma once
class Vector
{
public:
	float x, y, z;

	Vector();
	Vector(float x, float y);
	Vector(float x, float y, float z);
	~Vector();
	Vector operator+(const Vector& other) const;
	Vector operator-(const Vector& other) const;
	Vector operator*(float scalar) const;
	void Print() const;
	void Clear();
};
