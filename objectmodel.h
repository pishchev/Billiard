#ifndef OBJECTMODEL_H
#define OBJECTMODEL_H

#include <QOpenGLShaderProgram>


class ObjectModel
{
public:
    ObjectModel();

    void setTranslate(GLfloat x,GLfloat y,GLfloat z);
    void setRotate(GLfloat speed,GLfloat x,GLfloat y,GLfloat z);
    void addRotate(GLfloat speed,GLfloat x,GLfloat y,GLfloat z);
    void rotate(bool flag);
    QMatrix4x4 getRotate();
    QMatrix4x4 getTranslate();
    GLfloat rspeed =0;
    GLfloat rx=0;
    GLfloat ry=0;
    GLfloat rz=0;

    QMatrix4x4 rotateMatrix;

    GLfloat tx =0 ;
    GLfloat ty =0 ;
    GLfloat tz =0 ;

    bool rotation = true;
};

#endif // OBJECTMODEL_H
