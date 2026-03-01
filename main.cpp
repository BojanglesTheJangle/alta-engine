
// Made by BojanglesTheJangle on GitHub!!!

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

//Vertex and Fragment Shader Source Code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
	"{\n"
	"   FragColor = vec4(1f, 1f, 1f, 1.0f);\n"
	"}\0";

int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Establish and make a GLFW window

	GLfloat vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Left
		 0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Right
		 0.0f,  0.5f * float(sqrt(3)) / 3, 0.0f  // Top
	};

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

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); // Create Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // Attach Vertex Shader Source Code to Vertex Shader Object
	glCompileShader(vertexShader); // Compile Vertex Shader Object

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); // Create Fragment Shader Object
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL); // Attach Fragment Shader Source Code to Fragment Shader Object
	glCompileShader(fragmentShader); // Compile Fragment Shader Object

	GLuint shaderProgram = glCreateProgram(); // Create Shader Program Object

	glAttachShader(shaderProgram, vertexShader); // Attach Vertex Shader Object to Shader Program Object
	glAttachShader(shaderProgram, fragmentShader); // Attach Fragment Shader Object to Shader Program Object

	glLinkProgram(shaderProgram); // Link Shader Program Object

	glDeleteShader(vertexShader); // Delete Vertex Shader Object
	glDeleteShader(fragmentShader); // Delete Fragment Shader Object


	GLuint VAO, VBO; // Create Vertex Buffer Object and Vertex Array Object

	glGenVertexArrays(1, &VAO); // Generate Vertex Array Object
	glGenBuffers(1, &VBO); // Generate Vertex Buffer Object

	glBindVertexArray(VAO); // Bind Vertex Array Object

	glBindBuffer(GL_ARRAY_BUFFER, VBO); // Bind Vertex Buffer Object
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Copy Vertex Data to Vertex Buffer Object

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // Set Vertex Attribute Pointer)
	glEnableVertexAttribArray(0); // Enable Vertex Attribute

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind Vertex Buffer Object
	glBindVertexArray(0); // Unbind Vertex Array Object


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(0.0f, 0.145f, 0.408f, 0.8f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);


	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.145f, 0.408f, 0.8f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram); // Use Shader Program Object
		glBindVertexArray(VAO); // Bind Vertex Array Object
		glDrawArrays(GL_TRIANGLES, 0, 3); // Draw Triangle
		glfwSwapBuffers(window); // Swap Buffers

		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO); // Delete Vertex Array Object
	glDeleteBuffers(1, &VBO); // Delete Vertex Buffer Object
	glDeleteProgram(shaderProgram); // Delete Shader Program Object

	glfwDestroyWindow(window); // Closes Window
	glfwTerminate();
	return 0;
}