#pragma once

#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<sstream>
#include<string>

using std::string;

class shaders {
	string readShaderFile(const string& filpath);
	GLuint compileShader(GLenum shaderType, const string& shaderCode);

};

