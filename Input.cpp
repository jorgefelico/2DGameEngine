#include "Input.h"
#include "Screen.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <string.h>

Input::Input() {
	m_key = 0;
	m_isXClicked = false;
	m_isKeyPressed = false;
	m_isLeftButtonClicked = false;
	m_isRightButtonClicked = false;
	m_mousePositionX = 0;
	m_mousePositionY = 0;
	m_mouseMotionX = 0;
	m_mouseMotionY = 0;
		
	glfwSetKeyCallback(Screen::Instance()->window,KeyboardCallback);
	glfwSetMouseButtonCallback(Screen::Instance()->window, MouseButtonCallback);
	glfwSetCursorPosCallback(Screen::Instance()->window, MousePositionCallback);
};

Input* Input::Instance() {
	static Input* inputObject = new Input();
	return inputObject;
}

void Input::Update() {
	glfwPollEvents();
}

bool Input::IsXClicked(){
	return m_isXClicked;
}

bool Input::IsKeyPressed(){
	return m_isKeyPressed;
}

int Input::GetKey(){
	return m_key;
}

bool Input::IsLeftButtonClicked(){
	return m_isLeftButtonClicked;
}

bool Input::IsRightButtonClicked(){
	return m_isRightButtonClicked;
}

double Input::GetMousePositionX(){
	return m_mousePositionX;
}

double Input::GetMousePositionY(){
	return m_mousePositionY;
}

int Input::GetMouseMotionX(){
	return m_mouseMotionX;
}

int Input::GetMouseMotionY(){
	return m_mouseMotionY;
}

void Input::KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	Input::Instance()->m_key = key;

	if(action == GLFW_RELEASE){
		Input::Instance()->m_isKeyPressed = false;
		Input::Instance()->m_key = 0;
			
	}

	if(action == GLFW_PRESS) Input::Instance()->m_isKeyPressed = true;
}

void Input::MousePositionCallback(GLFWwindow* window, double xpos, double ypos){
	Input::Instance()->m_mousePositionX = xpos;
	Input::Instance()->m_mousePositionY = ypos;
}

void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods){
	if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
		Input::Instance()->m_isLeftButtonClicked = true;
	} else {
		Input::Instance()->m_isLeftButtonClicked = true;
	}

	if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
		Input::Instance()->m_isRightButtonClicked = true;
	} else {
		Input::Instance()->m_isRightButtonClicked = true;
	}
}
