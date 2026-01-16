
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include <thread>

void framebuffer_resize_handler(GLFWwindow* win, int width, int height){
	glViewport(0,0,width,height);
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Planetary Sim", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }


	glViewport(0,0,800,600);
	glfwSetFramebufferSizeCallback(window, framebuffer_resize_handler);
	//on input section of opengl docs
	

    glEnable(GL_DEPTH_TEST);


	std::srand(0);
	float cvals[4];
    while (!glfwWindowShouldClose(window)) {
	
		
		for(int i = 0; i<4; ++i){
			cvals[i] = (static_cast<float>(std::rand())/RAND_MAX);
		}

        glClearColor(cvals[0], cvals[1], cvals[2], cvals[3]);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		std::this_thread::sleep_for(std::chrono::seconds(1));
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
