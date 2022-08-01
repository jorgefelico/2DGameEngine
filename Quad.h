#ifndef QUAD_H
#define QUAD_H

#include "glad.h"

class Quad
{
public:
    Quad();
    ~Quad();
    void Render();

private:
    GLint m_vertexID;
    GLint m_colorID;
    GLuint m_VAO;
    GLuint m_vertexVBO;
    GLuint m_colorVBO;
};

#endif