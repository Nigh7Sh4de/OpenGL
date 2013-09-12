#include <GL/glfw3.h>

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



//// Include standard headers
//#include <stdio.h>
//#include <stdlib.h>
//
//// Include GLEW. Always include it before gl.h and glfw.h, since it's a bit magic.
//#include <GL/glew.h>
//
//// Include GLFW
//#define GLFW_INCLUDE_GLU
//#include <GL/glfw3.h>
//
//// Include GLM
//#include <glm/glm.hpp>
//using namespace glm;
//
//int main(){
//	// Initialise GLFW
//	if( !glfwInit() )
//	{
//		fprintf( stderr, "Failed to initialize GLFW\n" );
//		return -1;
//	}
//
//	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL
// 
//	// Open a window and create its OpenGL context
//	GLFWwindow* mywindow = glfwCreateWindow( 1024, 768, "My Super Duper Awesome OpenGL window made with GLFW :)", NULL, NULL );
//	if( !mywindow )
//	{
//		fprintf( stderr, "Failed to open GLFW window\n" );
//		glfwTerminate();
//		return -1;
//	}
// 
//	// Initialize GLEW
//	glewExperimental=true; // Needed in core profile
//	if (glewInit() != GLEW_OK) {
//		fprintf(stderr, "Failed to initialize GLEW\n");
//		return -1;
//	}
// 
//	// Ensure we can capture the escape key being pressed below
//	glfwSetInputMode( mywindow, GLFW_STICKY_KEYS, GL_TRUE );
// 
//	do {
//		// Draw nothing, see you in tutorial 2 !
// 
//		// Swap buffers
//		glfwSwapBuffers();
// 
//	} // Check if the ESC key was pressed or the window was closed
//	while( glfwGetKey( GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
//	glfwGetWindowParam( GLFW_OPENED ) );
//
//}