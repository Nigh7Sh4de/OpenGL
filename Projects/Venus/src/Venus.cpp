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
	
	GLFWwindow* window = glfwCreateWindow(1920, 1080, "My Super Awesome OpenGL window!", glfwGetPrimaryMonitor(), nullptr);
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
		" outColor = vec4(1-Color, 1.0);"
		"}";
	
	// Create Vertex Array Object
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create a Vertex Buffer Object and copy the vertex data to it
    GLuint vbo;
    glGenBuffers(1, &vbo);
	
	//Create an Element Buffer Object
	GLuint ebo;
	glGenBuffers(1, &ebo);
	
	float vertices[] = {
		 0.0f,  0.5f, 1.0f, 0.0f, 0.0f, // Vertex 1: Red
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // Vertex 2: Green
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f  // Vertex 3: Blue
	};
	
	GLuint elements[] = {
		0, 1, 2,
		// 2, 3, 0
	};

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
	
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
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
		
		/*************************************************************/
		
		
        // Set the color of the triangle
        GLfloat time = (GLfloat)clock() / (GLfloat)CLOCKS_PER_SEC;
        glUniform3f(uniColor, (sin(time * 4.0f) + 1.0f) / 2.0f, 0.0f, 0.0f);

        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        /* // Draw a triangle from the 3 vertices
        glDrawArrays(GL_TRIANGLES, 0, 3); */
		
		//Draw Elements as per elements array
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

		
		/*************************************************************/
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	
	return 0;
}