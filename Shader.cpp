#include "Shader.h"
#include <iostream>
#include <string>
#include <fstream>

Shader* Shader::Instance() {
    static Shader* shaderObject = new Shader();
    return shaderObject;
}

Shader::Shader() {
    m_shaderProgramID = 0;
    m_fragmentShaderID = 0;
    m_vertexShaderID = 0;
}

bool Shader::CreateProgram() {
    m_shaderProgramID = glCreateProgram();

    if(m_shaderProgramID == 0) {
        std::cout << "Could not create shader program" << std::endl;
        return false;
    }

    return true;
}

bool Shader::CreateShaders() {
    m_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    m_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

    if(m_fragmentShaderID == 0) {
        std::cout << "Could not create fragment shader" << std::endl;
        return false;
    }

    if(m_vertexShaderID == 0) {
        std::cout << "Could not create vertex shader" << std::endl;
        return false;
    }

    return true;
}

bool Shader::CompileShaders(const std::string& filename, ShaderType shaderType) {
    std::fstream file;
    std::string text;
    std::string sourceCode;
    GLuint shaderID = (shaderType == ShaderType::VERTEX_SHADER ? m_vertexShaderID : m_fragmentShaderID);

    file.open(filename);

    if(!file) {
        std::cout << "Could not open/read shader file: " << filename << std::endl;
    }
    
    while(!file.eof()){
        std::getline(file,text);
        sourceCode += text + "\n";
    }

    file.close();

    const GLchar* finalSourceCode = sourceCode.c_str();

    glShaderSource(shaderID, 1, &finalSourceCode, nullptr);

    glCompileShader(shaderID);

    GLint errorCode;

    glGetShaderiv(shaderID, GL_COMPILE_STATUS,&errorCode);

    if(errorCode == GL_TRUE) {
        std::cout << "Shader compilation successful" << std::endl;
        return true;
    } else {
        char errorMessage[1000];
        GLsizei bufferSize = 1000;
        glGetShaderInfoLog(shaderID,bufferSize, &bufferSize,errorMessage);
        std::cout << "Shader Error: " << errorMessage << std::endl;
        return false;
    }
}

void Shader::AttachShaders() {
    glAttachShader(m_shaderProgramID,m_vertexShaderID);
    glAttachShader(m_shaderProgramID,m_fragmentShaderID);
}

bool Shader::LinkProgram() {
    glLinkProgram(m_shaderProgramID);
    glUseProgram(m_shaderProgramID);

    GLint errorCode;

    glGetProgramiv(m_shaderProgramID, GL_LINK_STATUS,&errorCode);

    if(errorCode == GL_TRUE) {
        std::cout << "Shader linking successful" << std::endl;
        return true;
    } else {
        char errorMessage[1000];
        GLsizei bufferSize = 1000;
        glGetProgramInfoLog(m_shaderProgramID,bufferSize, &bufferSize,errorMessage);
        std::cout << "Shader Linking Error: " << errorMessage << std::endl;
        return false;
    }
}

void Shader::DetachShaders() {
    glDetachShader(m_shaderProgramID,m_vertexShaderID);
    glDetachShader(m_shaderProgramID, m_fragmentShaderID);
}

void Shader::DestroyShaders() {
    glDeleteShader(m_vertexShaderID);
    glDeleteShader(m_fragmentShaderID);
}

void Shader::DestroyProgram() {
    glDeleteProgram(m_shaderProgramID);
}