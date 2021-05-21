#ifndef SPHERE_H
#define SPHERE_H

#include <QOpenGLShaderProgram>
#include <vector>
#include "object.h"

class Sphere
{
public:
    Sphere(float radius,float stackCount,float sectorCount );

    std::vector<GLfloat> getVertex();
    std::vector<GLfloat> getNormals();
    std::vector<GLfloat> getTexCoord();
    std::vector<Vertex> getVertexs();


private:

    void buildVertex(float stackCount,float sectorCount);
    void buildIndexes(float stackCount,float sectorCount);

    GLfloat rad = 1;

    std::vector<GLfloat> vertices;
    std::vector<int> indices;
    std::vector<GLfloat> normals;
    std::vector<GLfloat> texCoords;
};

#endif // SPHERE_H
