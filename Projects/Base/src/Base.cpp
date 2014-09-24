// #include "../include/GL/glew.h"
#define GLEW_STATIC

#include <GL/glew.h>
#include <GL/glfw3.h>
#include <GLSLTools.h>
#include <fstream>
#include <sstream>
#include <iostream>

// const GLchar* vertexSource =
//     "#version 150 core\n"
//     "in vec2 position;"
//     "void main() {"
//     " gl_Position = vec4(position, 0.0, 1.0);"
//     "}";

// const GLchar* fragmentSource =
//     "#version 150 core\n"
//     "out vec4 outColor;"
//     "void main() {"
//     " outColor = vec4(1.0, 1.0, 1.0, 1.0);"
//     "}";

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 450, "Mah Base Project", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    glewInit();
    // Create Vertex Array Object
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    // Create a Vertex Buffer Object and copy the vertex data to it
    GLuint vbo;
    glGenBuffers(1, &vbo);
    GLfloat vertices[] = {
    0.0f, 0.5f,
    0.5f, -0.5f,
    -0.5f, -0.5f
    };
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    const char* vertexSource = loadSource("VertexSource.glsl");

    const char* fragmentSource = loadSource("FragmentSource.glsl");

    GLint status = GL_TRUE;
    
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
    // cout<< "Vertex" << status << endl;

    // Create and compile the fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
    // cout<< "Fragment" << status << endl;

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
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // Draw a triangle from the 3 vertices
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // Swap buffers

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}