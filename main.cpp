#include "Screen.h"
#include "Input.h"
#include <GLFW/glfw3.h>
#include <iostream>

bool isAppRunning = true;

int main(void){
	Screen::Instance()->Initialize();

	while(isAppRunning) {	
		Screen::Instance()->ClearScreen();
		Screen::Instance()->Render();	
		Input::Instance()->Update();

		// Exit App on Escape
		if(Input::Instance()->GetKey() == GLFW_KEY_ESCAPE) isAppRunning = false;
	}

	Screen::Instance()->Shutdown();
}
