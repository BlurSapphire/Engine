#include "window.h"
#include "../backend/shader_config.h"
#include <iostream>



void Window::init() {

    std::vector<glm::vec3> vertices = {
        // Position
        glm::vec3(-0.5f, -0.5f, -0.5f),
        glm::vec3(0.5f, -0.5f, -0.5f),
        glm::vec3(0.5f,  0.5f, -0.5f),
        glm::vec3(-0.5f,  0.5f, -0.5f),
        glm::vec3(-0.5f, -0.5f,  0.5f),
        glm::vec3(0.5f, -0.5f,  0.5f),
        glm::vec3(0.5f,  0.5f,  0.5f),
        glm::vec3(-0.5f,  0.5f,  0.5f)
    };

    std::vector<GLuint> indices = {
        0, 1, 2, 2, 3, 0, // Bottom face
        4, 5, 6, 6, 7, 4, // Top face
        0, 1, 5, 5, 4, 0, // Front face
        2, 3, 7, 7, 6, 2, // Back face
        0, 3, 7, 7, 4, 0, // Left face
        1, 2, 6, 6, 5, 1  // Right face
    };
    Mesh cube(vertices, indices);
    vertexPath = "../shaders/vertex_shader.glsl";
    fragmentPath = "../shaders/fragment_shader.glsl";

   
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
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);

        
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::lookAt(glm::vec3(3.0f, 3.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);

        GLuint modelLoc = glGetUniformLocation(shaderProgram, "model");
        GLuint viewLoc = glGetUniformLocation(shaderProgram, "view");
        GLuint projLoc = glGetUniformLocation(shaderProgram, "projection");

        glUseProgram(shaderProgram);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        
        cube.Draw(shaderProgram);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Window::cleanup() {
    glDeleteProgram(shaderProgram);
    glfwDestroyWindow(window);
    glfwTerminate();
}
