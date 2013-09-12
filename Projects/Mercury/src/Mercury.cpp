/* // Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#define GLEW_STATIC
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

	// Open a window and create its OpenGL context
	GLFWmonitor * mySuperAwesomeMonitorPtr;
	GLFWwindow * nySuperAwesomeWindowPtr;
	
	if( !glfwCreateWindow( 1024, 768, "My super awesome window", mySuperAwesomeMonitorPtr, nySuperAwesomeWindowPtr ) )
	{
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return -1;
	}

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	//glfwSetWindowTitle( "Tutorial 01" );

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode( nySuperAwesomeWindowPtr, GLFW_STICKY_KEYS, GL_TRUE );

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	do{
		// Draw nothing, see you in tutorial 2 !

		// Swap buffers
		glfwSwapBuffers( nySuperAwesomeWindowPtr );

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey( nySuperAwesomeWindowPtr, GLFW_KEY_ESCAPE ) != GLFW_PRESS );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
 */

#include "../include/GL/glfw3.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

