#include <vector>
#include <iostream>

#include "Vector.h"
#include "Matrix.h"

using namespace std;

Matrix::Matrix()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				values[i][j] = 1;
			}
			else
			{
				values[i][j] = 0;
			}
		}
	}
}
Matrix::Matrix(float vals[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			values[i][j] = values[i][j];
		}
	}
}
Matrix::~Matrix()
{

}

Matrix Matrix::operator*(const Matrix& other) const {
	Matrix result;

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			result.values[row][col] = 0;

			for (int k = 0; k < 3; k++) {
				result.values[row][col] += values[row][k] * other.values[k][col];
			}
		}
	}

	return result;
}

Vector Matrix::operator*(const Vector& other)
{
	float x = (values[0][0] * other.x) + (values[1][0] * other.y) + (values[2][0] * other.z);
	float y = (values[0][1] * other.x) + (values[1][1] * other.y) + (values[2][1] * other.z);
	float z = (values[0][2] * other.x) + (values[1][2] * other.y) + (values[2][2] * other.z);
	return Vector(x,y,z);
}

void Matrix::Reset()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				values[i][j] = 1;
			}
			else
			{
				values[i][j] = 0;
			}
		}
	}
}
void Matrix::Translate(float tx, float ty) {
	Matrix translationMatrix;

	translationMatrix.values[0][0] = 1;
	translationMatrix.values[1][1] = 1;
	translationMatrix.values[2][2] = 1;

	translationMatrix.values[0][2] = tx;
	translationMatrix.values[1][2] = ty;

	*this = *this * translationMatrix;
}

void Matrix::Scale(float x, float y)
{
	Matrix scalingMatrix;

	scalingMatrix.values[0][0] = x;
	scalingMatrix.values[1][1] = y;
	scalingMatrix.values[2][2] = 1;

	*this = *this * scalingMatrix;
}
void Matrix::Rotate(float theta)
{
	Matrix rotationMatrix;

	rotationMatrix.values[0][0] = cosf(theta);
	rotationMatrix.values[0][1] = sinf(theta) * -1.0f;
	rotationMatrix.values[1][0] = sinf(theta);
	rotationMatrix.values[1][1] = cosf(theta);
	rotationMatrix.values[2][2] = 1;

	*this = *this * rotationMatrix;

}

void Matrix::Print() const
{
	cout << "[ " << values[0][0] << ", " << values[0][1] << ", " << values[0][2] << " ]\n";
	cout << "[ " << values[1][0] << ", " << values[1][1] << ", " << values[1][2] << " ]\n";
	cout << "[ " << values[2][0] << ", " << values[2][1] << ", " << values[2][2] << " ]\n";
}