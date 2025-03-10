#pragma once
#include <vector>
#include "Vector.h"
using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(float vals[3][3]);
	~Matrix();

	Matrix operator*(const Matrix& other) const;
	Vector operator*(const Vector& other);

	void Reset();
	void Translate(float tx, float ty);
	void Scale(float x, float y);
	void Rotate(float theta);

	void Print() const;

	float values[3][3];

private:

};
