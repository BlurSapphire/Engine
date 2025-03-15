#include "window.h"
#include "shader_config.h"
#include <iostream>

void Window::init() {
    vertexPath = "shaders/vertex_shader.glsl";
    fragmentPath = "shaders/fragment_shader.glsl";

   
    if (!glfwInit()) {
        std::cerr << "Error: GLFW not initialized!" << std::endl;
        return;
    }

    
    window = glfwCreateWindow(800, 800, "Engine", nullptr, nullptr);
    if (!window) {
        std::cerr << "Error: Window not created!" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

   
    if (glewInit() != GLEW_OK) {
        std::cerr << "Error: GLEW initialization failed!" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return;
    }

    
    shaders shaderObj;
    shaderProgram = shaderObj.createShaderProgram(vertexPath.c_str(), fragmentPath.c_str());
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
