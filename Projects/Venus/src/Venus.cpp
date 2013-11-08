// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include "../include/GL/glew.h"

// Include GLFW
#include "../include/GL/glfw3.h"

// Include GLM
#include "../include/glm/glm.hpp"
using namespace glm;

int main( void )
{
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window;
	
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	do{
		// Draw nothing, see you in tutorial 2 !

		// Swap buffers
		glfwSwapBuffers(window);

	} // Check if the ESC key was pressed or the window was closed
	while (!glfwWindowShouldClose(window));

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

// #include "../include/GL/glfw3.h"

// int main(void)
// {
    // GLFWwindow* window;

    // /* Initialize the library */
    // if (!glfwInit())
        // return -1;

    // /* Create a windowed mode window and its OpenGL context */
    // window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    // if (!window)
    // {
        // glfwTerminate();
        // return -1;
    // }

    // /* Make the window's context current */
    // glfwMakeContextCurrent(window);

    // /* Loop until the user closes the window */
    // while (!glfwWindowShouldClose(window))
    // {
        // /* Render here */
		
		// // Ugly pre-OpenGL-3.0 code:
		// glBegin(GL_TRIANGLES);
		// glColor3f(0.05859375f, 0.36328125f, 0.22265625f);
		// glVertex3f(-0.5f, 0.5f, 0.0f);
		// glColor3f(1.0f, 0.36328125f, 0.22265625f);
		// glVertex3f(0.0f, -0.5f, 0.0f);
		// glColor3f(0.05859375f, 1.0f, 0.22265625f);
		// glVertex3f(0.5f, 0.5f, 0.0f);
		// glEnd();
		
		// // :end ugly code
		
        // /* Swap front and back buffers */
        // glfwSwapBuffers(window);

        // /* Poll for and process events */
        // glfwPollEvents();
    // }

    // glfwTerminate();
    // return 0;
// }