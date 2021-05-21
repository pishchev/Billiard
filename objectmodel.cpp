#include "objectmodel.h"

ObjectModel::ObjectModel()
{

}

void ObjectModel::setTranslate(GLfloat x,GLfloat y,GLfloat z)
{
    tx= x;
    ty= y;
    tz= z;

}

void ObjectModel::addRotate(GLfloat speed,GLfloat x,GLfloat y,GLfloat z)
{
    QVector3D v(x,y,z);
    auto q = QQuaternion::fromRotationMatrix(rotateMatrix.inverted().normalMatrix());
    v = q*v;
    rotateMatrix.rotate(QQuaternion::fromAxisAndAngle(v, speed));
}

void ObjectModel::setRotate(GLfloat speed,GLfloat x,GLfloat y,GLfloat z)
{
    rotateMatrix = QMatrix4x4();
    rotateMatrix.rotate(speed,x,y,z);
}

QMatrix4x4 ObjectModel::getRotate()
{
    return rotateMatrix;
}

QMatrix4x4 ObjectModel::getTranslate()
{
    QMatrix4x4 mat;
    mat.translate(tx,ty,tz);
    return mat;
}

void ObjectModel::rotate(bool flag)
{
    rotation = flag;
}

