#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Window {
public:
    void init();
    void update();
    void cleanup();

private:
    GLFWwindow* window;
    GLuint shaderProgram;
    std::string vertexPath;
    std::string fragmentPath;
};
