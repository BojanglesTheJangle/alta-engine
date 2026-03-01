
// Made by BojanglesTheJangle on GitHub!!!

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Establish and make a GLFW window

	GLFWwindow* window = glfwCreateWindow(800, 800, "Alta", NULL, NULL); // Specifications

	if (window == NULL) {  // Error Check
		std::cout << "Failed to create a windows with GLFW\n";
		glfwTerminate();
		return -1;
	}
	else {
		std::cout << "GLFW window created successfully!!\n";
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0, 0, 800, 800);

	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);


	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}


	glfwDestroyWindow(window); // Closes Window
	glfwTerminate();
	return 0;
}