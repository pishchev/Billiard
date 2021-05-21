#include "sourcelight.h"

LightObject::LightObject(){};
void LightObject::setColor(QColor color_)
{
    color = color_;
};
QColor LightObject::getColor()
{
    return color;
}

void LightObject::render(QOpenGLShaderProgram *m_program ,QOpenGLFunctions* scene)
{
    m_program->setUniformValue("ambientColor", getColor());
    m_program->setUniformValue("ka", 5.0f);

    m_program->setUniformValue("rtmatrix", model.getRotate());
    m_program->setUniformValue("trmatrix" , model.getTranslate());

    m_program->setUniformValue(textName.data(),0);
    m_program->setUniformValue(normName.data(),1);
    m_program->setUniformValue("shaiderMap",1);

    m_vao->bind();
    scene->glActiveTexture(GL_TEXTURE0);
    texture->bind();
    scene->glActiveTexture(GL_TEXTURE1);
    normalMap->bind();
    glPolygonMode(GL_FRONT, GL_FILL);
    glDrawArrays(GL_TRIANGLES, 0, vertexs.size());
}

LightFactors::LightFactors(){};
