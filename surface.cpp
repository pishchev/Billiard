#include "surface.h"

Surface::Surface()
{

}

std::vector<Vertex> Surface::surface(GLfloat w ,GLfloat h , GLfloat xtime , GLfloat ytime)
{
    std::vector <Vertex> vert;

    Vertex a;
    a.normal = {0,1,0};

    a.vertex = {-w,0,h};
    a.texCoord = {xtime,0};
    vert.push_back(a);

    a.vertex = {w,0,h};
    a.texCoord = {0,0};
    vert.push_back(a);

    a.vertex = {-w,0,-h};
    a.texCoord = {xtime,ytime};
    vert.push_back(a);

    a.vertex = {-w,0,-h};
    a.texCoord = {xtime,ytime};
    vert.push_back(a);

    a.vertex = {w,0,h};
    a.texCoord = {0,0};
    vert.push_back(a);

    a.vertex = {w,0,-h};
    a.texCoord = {0,ytime};
    vert.push_back(a);

    return vert;

}
