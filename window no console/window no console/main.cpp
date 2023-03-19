#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;

int main() {
	//glfw initialisation:
	if (!glfwInit()) {
		std::cout << "GLFW initialisation failed!\n";
		glfwTerminate();
		return 1;
	}

	//versions:
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// no backwards compatibility:
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// forwards compatibility enable:
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//make the window:
	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "ben's window", NULL, NULL);

	//if the window didnt work:
	if (!mainWindow) {
		std::cout << "window creation failed!\n";
		glfwTerminate();
		return 1;
	}

	//get buffer info:
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//make a context:
	glfwMakeContextCurrent(mainWindow);

	//glew experimental:
	glewExperimental = GL_TRUE;

	//initialise GLEW:
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW initialisation failed!\n";
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	//viewport:
	glViewport(0, 0, bufferWidth, bufferHeight);

	//main loop:
	while (!glfwWindowShouldClose(mainWindow)) {
		//glfw poll events:
		glfwPollEvents();
		// clear screen to a color:
		glClearColor(0.1, 0.1, 0.1, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		//swap buffers:
		glfwSwapBuffers(mainWindow);
	}

	return 0;
}