#include "../include/GL/glew.h"

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
		
		//Ugly pre-OpenGL-3.0 code:
		glBegin(GL_TRIANGLES);
		glColor3f(0.05859375f, 0.36328125f, 0.22265625f);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glColor3f(1.0f, 0.36328125f, 0.22265625f);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glColor3f(0.05859375f, 1.0f, 0.22265625f);
		glVertex3f(0.5f, -0.5f, 0.0f);
		glEnd();
		
		//:end ugly code
		
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}