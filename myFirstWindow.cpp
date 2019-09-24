// glad beforw glfw
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// Create the main function where we will instantiate the GLFW window
int main()
{
	// ---- INITIAL SET UP ----
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// GLAD manages function pointers for OpenGL so we want to initialize it before
	// calling any OpenGL function, lets us know if it fails.
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// ---- CREATE A RE-SIZABLE WINDOW ----
	// Set the dimensions of the rendering window via the glViewport:
	glViewport(0, 0, 800, 600);

	// When the user resizes a window the viewport should also resize. So we register
	// a callback function on the window that gets called every time the window
	// is re-sized. The 1st arg is a window, and the next two are the new dimensions.
	// The 'framebuffer_size_callback' function is implemented above main


	// Tell GLFW that we want to call this fucntion on ever re-size by
	// actually registering it
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// 'Render loop': so the window only closes when we actually close it
	while(!glfwWindowShouldClose(window))
	{
		// check for input (ie: escape key)
		processInput(window);

		// Render
		// Clear the screen so we don't see results from previous iteration,
		// to make sure it cleared, set the screen to a greenish-blue whenever
		// it is cleared.
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// check and call events, and swap the buffers (to avoid flickering)
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Clean up and exit the program
	glfwTerminate();
	return 0;

}

// For input control, tells us whether a key is currently being pressed
void processInput(GLFWwindow *window)
{
	// Check if user pressed the escape key, if not return GLFW_RELEASE
	// If they did press it, close GLFW by setting WindowShouldClose to true
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// For adjusting the window when the user re-sizes it
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
