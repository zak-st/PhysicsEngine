#pragma once
#include <string>
#include<GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

class Shader
{
public:
	Shader(const string& vertex_path, const string& fragment_path);
	~Shader();

	void Use();

	void SetMatrix4(const std::string& name, const glm::mat4& matrix);
	void SetVector4f(const std::string& name, const glm::vec4& value);
	void SetInteger(const std::string& name, int value);

	GLuint GetID() const { return shaderID; }
private:
	GLuint shaderID;
	string LoadShaderSource(const string& path);
	GLuint CompileShader(const string& source, GLenum type);
};