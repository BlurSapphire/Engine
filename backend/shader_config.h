#pragma once

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class shaders {
public:
    static GLuint createShaderProgram(const char* vertexPath, const char* fragmentPath);

private:
    static std::string readShaderSource(const std::string& filepath);
    static GLuint compileShader(GLenum shaderType, const std::string& shaderCode);
};
