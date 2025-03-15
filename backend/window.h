#pragma once

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<sstream>

using std::cerr, std::endl, std::string;
class Window {
public:
	void init();
	void update();
	void cleanup();
private:
	GLFWwindow* window;
	GLuint shaderProgram;
	string vertexPath;
	string fragmentPath;
};
