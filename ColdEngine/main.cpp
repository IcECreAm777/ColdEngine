#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Callback function for glfw when the window is resized by the user
void framebuffer_size_callback(GLFWwindow* window, const int width, const int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	// initializes glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// initializes a window and terminates when it couldn't be created
	GLFWwindow* window = glfwCreateWindow(800, 600, "ColdEngine", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// initializes glad (to initialize fitting drivers and stuff)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//TODO change to full screen somehow
	// set the initial window size
	glViewport(0, 0, 800, 600);

	// binds the callback to the resize event
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Render Loop
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
