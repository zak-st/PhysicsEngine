#pragma once
#include <string>
#include<GL/glew.h>

using namespace std;

class Shader
{
public:
	Shader(const string& vertex_path, const string& fragment_path);
	~Shader();

	void Use();
	GLuint GetID() const { return shaderID; }
private:
	GLuint shaderID;
	string LoadShaderSource(const string& path);
	GLuint CompileShader(const string& source, GLenum type);
};