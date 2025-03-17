#pragma once

#include<glm/glm.hpp>
#include<vector>
#include<GL/glew.h>
#include<iostream>

using std::vector, glm::vec3;


class Mesh {
public:
	Mesh() : VAO(0), VBO(0), EBO(0), shaderProgram(0) {}  
	Mesh(vector<vec3> vertices, vector<GLuint> indices);
	~Mesh();

	void Draw(GLuint shaderProgram);

private:
	GLuint VAO, VBO, EBO;
	GLuint shaderProgram;
	vector<vec3> vertices;
	vector<GLuint> indices;
};