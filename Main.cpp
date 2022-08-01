#include "Screen.h"
#include "Input.h"
#include <iostream>
#include "Shader.h"
#include "Quad.h"

bool isAppRunning = true;

int main(void)
{
	Screen::Instance()->Initialize();

	if(!Shader::Instance()->CreateProgram()) {
		return false;
	}
	
	if(!Shader::Instance()->CreateShaders()){
		return false;
	}

	Shader::Instance()->CompileShaders("Shaders/Main.frag",Shader::ShaderType::FRAGMENT_SHADER);
	Shader::Instance()->CompileShaders("Shaders/Main.vert",Shader::ShaderType::VERTEX_SHADER);

	Shader::Instance()->AttachShaders();

	if(!Shader::Instance()->LinkProgram()){
		return false;
	}


	Quad my_quad = Quad();

			
		



	while (isAppRunning)
	{
		Screen::Instance()->ClearScreen();
		
		
		my_quad.Render();
		Screen::Instance()->Render();
		Input::Instance()->Update();



		// Exit App on Escape
		if (Input::Instance()->GetKey() == GLFW_KEY_ESCAPE)
			isAppRunning = false;
	}

	

	Shader::Instance()->DetachShaders();
	Shader::Instance()->DestroyShaders();
	Shader::Instance()->DetachShaders();
	Screen::Instance()->Shutdown();
}
