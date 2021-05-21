#ifndef SOURCELIGHT_H
#define SOURCELIGHT_H
#include <QOpenGLShaderProgram>
#include <QColor>
#include <vector>
#include "object.h"

class LightObject : public Object
{
public:
    LightObject();
    virtual void render(QOpenGLShaderProgram *m_program ,QOpenGLFunctions* scene) override;
    void setColor(QColor color_);
    QColor getColor();

private:
    QColor color = QColor(255,255,255);
};

class LightFactors
{
public:
    LightFactors();

    float ka = 0.5;
    float kd = 40;
    float ks = 70;
    float n = 4.0f;
    float k = 0.8f;
    float p = 2.0f;
};

#endif // SOURCELIGHT_H
