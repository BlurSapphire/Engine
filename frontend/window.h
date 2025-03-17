#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include<vector>
#include<glm/glm.hpp>
#include"../backend/mesh.h"
#include "../backend/shader_config.h"
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>


class Window {
public:
    void init();
    void update();
    void cleanup();

private:
    Mesh cube;
    GLFWwindow* window;
    GLuint shaderProgram;
    std::string vertexPath;
    std::string fragmentPath;
};
