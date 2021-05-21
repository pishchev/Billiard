#ifndef OBJECT_H
#define OBJECT_H
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <vector>
#include <array>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>
#include <QOpenGLExtraFunctions>
#include <QOpenGLFunctions_4_0_Core>
#include <string>

#include "objectmodel.h"


struct Vertex
{
    std::array<GLfloat , 3> vertex;
    std::array<GLfloat , 3> normal;
    std::array<GLfloat , 2> texCoord;
};

class Object
{
public:
    Object();
    //Object(const Object&) = default;
    void Init(std::vector<Vertex> verts,
                GLfloat rtSpeed,
                std::string textFile,
                std::string normFile,
                std::vector<QOpenGLShaderProgram*>m_program);

    virtual void render(QOpenGLShaderProgram *m_program ,QOpenGLFunctions* scene);

    std::vector<Vertex> vertexs;

    QOpenGLBuffer *m_vbo = nullptr;
    QOpenGLVertexArrayObject *m_vao = nullptr;

    std::string textName = "textureMap";
    std::string normName = "normalMap";

    std::shared_ptr<QOpenGLTexture> texture, normalMap;

    ObjectModel model;




    template<typename T>
    static void render(std::vector<T>& objects ,QOpenGLShaderProgram *m_program ,QOpenGLFunctions* scene)
    {
        for (auto obj = objects.begin() ; obj!= objects.end(); ++obj)
        {
            obj->render(m_program , scene);
        }
    }

    template<typename T1,typename T2>
    static void render(std::map<T1,T2>& objects ,QOpenGLShaderProgram *m_program ,QOpenGLFunctions* scene)
    {
        for (auto it = objects.begin() ; it!= objects.end() ; ++it)
        {
            it->second.render(m_program,scene);
        }
    }

};

#endif // OBJECT_H
