#pragma once

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using std::string;
class shaders {
public:
    static GLuint createShaderProgram(const char* vertexPath, const char* fragmentPath);
    static string readShaderSource(const std::string& filepath);
private:
    static GLuint compileShader(GLenum shaderType, const string& shaderCode);
};