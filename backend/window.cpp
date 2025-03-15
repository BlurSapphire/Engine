#include<iostream>
#include "window.h"
#include"shader_config.h"

void Window::init() {
	
	vertexPath = "shaders/vertex_shader.glsl";
	fragmentPath = "shaders/fragment_shader.glsl";
	if (!glfwInit()) {
		cerr << "Error: glfw not initialised!" << endl;
	}
	shaders shaderObj;
	shaderProgram = shaderObj.createShaderProgram(vertexPath.c_str(), fragmentPath.c_str());


	window = glfwCreateWindow(800, 800, "Engine", nullptr, nullptr);
	if (!window) {
		cerr << "Window not initialises" << endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		cerr << "Error: GLEW initialization failed!" << endl;
		glfwDestroyWindow(window);
		glfwTerminate();
		return;
	}

}

void Window::update() {
	while (!glfwWindowShouldClose(window)) {
		

		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

}

void Window::cleanup() {
	glDeleteProgram(shaderProgram);
	glfwDestroyWindow(window);
	glfwTerminate();
}