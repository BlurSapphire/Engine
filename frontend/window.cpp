#include "window.h"
#include <iostream>



void Window::init() {

    vector<glm::vec3> vertices = {
        
       vec3(-0.5f, -0.5f, -0.5f),
       vec3(0.5f, -0.5f, -0.5f),
       vec3(0.5f,  0.5f, -0.5f),
       vec3(-0.5f,  0.5f, -0.5f),
       vec3(-0.5f, -0.5f,  0.5f),
       vec3(0.5f, -0.5f,  0.5f),
       vec3(0.5f,  0.5f,  0.5f),
       vec3(-0.5f,  0.5f,  0.5f)
    };

   vector<GLuint> indices = {
        0, 1, 2, 2, 3, 0, 
        4, 5, 6, 6, 7, 4, 
        0, 1, 5, 5, 4, 0, 
        2, 3, 7, 7, 6, 2,
        0, 3, 7, 7, 4, 0, 
        1, 2, 6, 6, 5, 1 
    };

   
    cube = Mesh(vertices, indices);
    vertexPath = "../Engine/shaders/vertex_shader.glsl";
    fragmentPath = "../Engine/shaders/fragment_shader.glsl";

   
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
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::lookAt(glm::vec3(3.0f, 3.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

        GLuint modelLoc = glGetUniformLocation(shaderProgram, "model");
        GLuint viewLoc = glGetUniformLocation(shaderProgram, "view");
        GLuint projLoc = glGetUniformLocation(shaderProgram, "projection");

        glUseProgram(shaderProgram);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        cube.Draw(shaderProgram);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
}

void Window::cleanup() {
    glDeleteProgram(shaderProgram);
    glfwDestroyWindow(window);
    glfwTerminate();
}
