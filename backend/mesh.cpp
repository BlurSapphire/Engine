#include"mesh.h"

Mesh::Mesh(vector<vec3> vertices, vector<GLuint> indices) {
	this->vertices = vertices;
	this->indices = indices;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	 
}