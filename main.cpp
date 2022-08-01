#include "Screen.h"
#include "Input.h"
#include <iostream>
#include "Shader.h"

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

	GLfloat vertices[] = {
			-0.5f, 0.5f,0.0f,
			0.5f, 0.5f,0.0f,
			-0.5,-0.5f,0.0f,
			-0.5f,-0.5f,0.0f,
			0.5f,0.5f,0.0f,
			0.5f,-0.5f,0.0f
		};

		GLfloat colors[] = {
			1.0f,0.0f,0.0f,
			0.0,1.0f,0.0f,
			0.0f,0.0f,1.0f,
			0.0f,0.0f,1.0f,
			0.0f,1.0f,0.0f,
			1.0f,1.0f,0.0f
		};

		GLuint shaderProgram = Shader::Instance()->GetShaderProgramID();
		GLint vertexID = glGetAttribLocation(shaderProgram, "vertexIn");
		GLint colorID = glGetAttribLocation(shaderProgram, "colorIn");

		GLuint VertexVBO;
		GLuint ColorVBO;

		GLuint VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

			glGenBuffers(1, &VertexVBO);
			glGenBuffers(1, &ColorVBO);

			glBindBuffer(GL_ARRAY_BUFFER, VertexVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices, GL_STATIC_DRAW);
			glVertexAttribPointer(vertexID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
			glEnableVertexAttribArray(vertexID);


			glBindBuffer(GL_ARRAY_BUFFER, ColorVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(colors),colors, GL_STATIC_DRAW);
			glVertexAttribPointer(colorID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
			glEnableVertexAttribArray(colorID);
		glBindVertexArray(0);
		



	while (isAppRunning)
	{
		Screen::Instance()->ClearScreen();
		
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);

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
