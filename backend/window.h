#ifndef WINDOW_H
#define WINDOW_H

#include<GLFW/glfw3.h>
#include<iostream>
#include<sstream>

using std::cerr;
using std::endl;

class Window {
public:
	void init();
	void update();
private:
	GLFWwindow* window;
};

#endif 