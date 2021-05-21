#ifndef SURFACE_H
#define SURFACE_H
#include <QOpenGLShaderProgram>
#include <vector>


#include "object.h"

class Surface
{
public:
    Surface();

    static std::vector<Vertex> surface(GLfloat w ,GLfloat h , GLfloat xtime , GLfloat ytime);
};

#endif // SURFACE_H
