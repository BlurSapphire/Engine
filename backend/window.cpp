#include<iostream>
#include "window.h"


void Window::init() {
	if (!glfwInit()) {
		cerr << "Error: glfw not initialised!" << endl;
	}

	window = glfwCreateWindow(800, 800, "Engine", nullptr, nullptr);
	if (!window) {
		cerr << "Window not initialises" << endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	if (!glewInit() != GLEW_OK) {
		std::cerr << "GLEW initialising error!" << std::endl;
		
	}
}

void Window::update() {
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();

}