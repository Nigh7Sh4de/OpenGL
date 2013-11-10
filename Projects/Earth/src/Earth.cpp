#include <time.h>
#include <stdio.h>
#include <math.h>

#define GLEW_STATIC
#include "../include/GL/glew.h"

#include "../include/GL/glfw3.h"

int main() {
	
	glfwInit();
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	GLFWwindow* window = glfwCreateWindow(800, 600, "Earth", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;
	glewInit();
	
	///////////////////////////////
	
	// Shader sources
	const GLchar* vertexSource =
		"#version 150 core\n"
		"in vec2 position;"
		"in vec3 color;"
		"out vec3 Color;"
		"void main() {"
		" Color = color;"
		" gl_Position = vec4(position, 0.0, 1.0);"
		"}";
		
	const GLchar* fragmentSource =
		"#version 150 core\n"
		"in vec3 Color;"
		"out vec4 outColor;"
		"void main() {"
		" outColor = vec4(Color, 1.0);"
		"}";
	
	    // Create and compile the vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    // Create and compile the fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    // Link the vertex and fragment shader into a shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "outColor");
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    // Specify the layout of the vertex data
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), 0);
	
	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)(2*sizeof(float)));
	
	GLint uniColor = glGetUniformLocation(shaderProgram, "color");

	///////////////////////////////
	
	while (!glfwWindowShouldClose(window)) {
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
		
		/*************************************************************/
		
	    // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
     
		/*************************************************************/
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	
	return 0;
}