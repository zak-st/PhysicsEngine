#include <iostream>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
    std::string vertexSource = LoadShaderSource(vertexPath);
    std::string fragmentSource = LoadShaderSource(fragmentPath);

    //std::cout << "Vertex Shader Source:\n" << vertexSource << std::endl;
    //std::cout << "Fragment Shader Source:\n" << fragmentSource << std::endl;


    GLuint vertexShader = CompileShader(vertexSource, GL_VERTEX_SHADER);
    GLuint fragmentShader = CompileShader(fragmentSource, GL_FRAGMENT_SHADER);

    shaderID = glCreateProgram();
    //std::cout << "Shader Program ID: " << shaderID << std::endl;
    glAttachShader(shaderID, vertexShader);
    glAttachShader(shaderID, fragmentShader);
    glLinkProgram(shaderID);

    GLint success;
    glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderID, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        shaderID = 0; // Set shaderID to 0 if linking fails
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader() {
    glDeleteProgram(shaderID);
}

void Shader::Use() {

    if (shaderID == 0) {
        std::cerr << "ERROR: Shader ID is 0! Shader program was not initialized correctly." << std::endl;
        return;
    }

    glUseProgram(shaderID);
}

void Shader::SetMatrix4(const std::string& name, const glm::mat4& matrix) {
    GLint location = glGetUniformLocation(shaderID, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::SetVector4f(const std::string& name, const glm::vec4& value) {
    GLint location = glGetUniformLocation(shaderID, name.c_str());
    glUniform4fv(location, 1, glm::value_ptr(value));
}

void Shader::SetInteger(const std::string& name, int value) {
    GLint location = glGetUniformLocation(shaderID, name.c_str());
    glUniform1i(location, value);
}


std::string Shader::LoadShaderSource(const std::string& filepath) {
    std::ifstream file(filepath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

GLuint Shader::CompileShader(const std::string& source, GLenum type) {
    GLuint shader = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    else {
        //std::cout << "Shader compiled successfully: " << type << std::endl;
    }

    return shader;
}