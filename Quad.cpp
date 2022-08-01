#include "Quad.h"
#include "Shader.h"

Quad::Quad()
{
    GLfloat vertices[] = {
        -0.5f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        -0.5, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f};

    GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f};

    GLuint shaderProgram = Shader::Instance()->GetShaderProgramID();
    m_vertexID = glGetAttribLocation(shaderProgram, "vertexIn");
    m_colorID = glGetAttribLocation(shaderProgram, "colorIn");
    glGenVertexArrays(1, &m_VAO);

    glGenBuffers(1, &m_vertexVBO);
    glGenBuffers(1, &m_colorVBO);
    glBindVertexArray(m_VAO);

        glBindBuffer(GL_ARRAY_BUFFER, m_vertexVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(m_vertexID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(m_vertexID);

        glBindBuffer(GL_ARRAY_BUFFER, m_colorVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
        glVertexAttribPointer(m_colorID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(m_colorID);
    glBindVertexArray(0);
}

void Quad::Render()
{
    glBindVertexArray(m_VAO);
	    glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

Quad::~Quad()
{
    glDeleteBuffers(1,&m_vertexVBO);
	glDeleteBuffers(1,&m_colorVBO);
	glDeleteVertexArrays(1, &m_VAO);

	glDisableVertexAttribArray(m_vertexID);
	glDisableVertexAttribArray(m_colorID);
}

