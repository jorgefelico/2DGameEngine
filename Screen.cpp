#include "glad.h"
#include "Screen.h"
#include <GLFW/glfw3.h>
#include <iostream>

Screen::Screen() {
	window = nullptr;
}

Screen* Screen::Instance(){
	static Screen* screen = new Screen;
	return screen;
}

void Screen::ErrorCallback(int, const char* err_str)
{
    std::cout << "GLFW Error: " << err_str << std::endl;
}

bool Screen::Initialize() {
	if(!glfwInit()){
		std::cout << "Could not initialize GLFW" << std::endl;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,0);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
		glfwSetErrorCallback(Screen::Instance()->ErrorCallback);
		this->window = glfwCreateWindow(1280,720, "My Window",NULL,NULL);
		
		if (!this->window)
		{
			std::cout << "Could not create window instance" << std::endl;
			return false;
		}
	
		glfwMakeContextCurrent(window);
		glfwSwapInterval(1);
		if(!gladLoadGL()){
			std::cout << "Error loading extensions" << std::endl;
		}
		return true;
}

void Screen::ClearScreen(){
	glClear(GL_COLOR_BUFFER_BIT);
}


void Screen::Render(){
	glfwSwapBuffers(window);
}


void Screen::Shutdown(){
	std::cout << "Shutdown" << std::endl;
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

