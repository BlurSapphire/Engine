#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include<vector>
#include<glm/glm.hpp>
#include"../backend/mesh.h"

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
