#include "Screen.h"
#include "Input.h"
#include <iostream>
#include "Shader.h"

bool isAppRunning = true;

int main(void)
{
	Screen::Instance()->Initialize();

	Shader::Instance()->CreateProgram();
	Shader::Instance()->CreateShaders();

	Shader::Instance()->CompileShaders("Shaders/Main.frag",Shader::ShaderType::FRAGMENT_SHADER);
	Shader::Instance()->CompileShaders("Shaders/Main.vert",Shader::ShaderType::VERTEX_SHADER);

	Shader::Instance()->AttachShaders();
	Shader::Instance()->LinkProgram();

	while (isAppRunning)
	{
		Screen::Instance()->ClearScreen();
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
