#ifndef QUADMESH_H
#define QUADMESH_H

#include <QOpenGLShaderProgram>
#include <vector>
#include "object.h"

class QuadMesh
{
public:
    inline static std::vector<Vertex> getVertexs()
    {
        std::vector <Vertex> vert;

        Vertex a;
        a.normal = {0,0,1};

        a.vertex = {-1,1,0};
        a.texCoord = {0,1};
        vert.push_back(a);

        a.vertex = {1,1,0};
        a.texCoord = {1,1};
        vert.push_back(a);

        a.vertex = {-1,-1,0};
        a.texCoord = {0,0};
        vert.push_back(a);

        a.vertex = {-1,-1,0};
        a.texCoord = {0,0};
        vert.push_back(a);

        a.vertex = {1,1,0};
        a.texCoord = {1,1};
        vert.push_back(a);

        a.vertex = {1,-1,0};
        a.texCoord = {1,0};
        vert.push_back(a);

        return vert;
    }
};

#endif // QUADMESH_H
