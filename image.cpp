#include "image.h"

Texture::Texture()
{

}

void Texture::loadImage(std::string file)
{
    tex = new QOpenGLTexture(QImage(file.data()));
    tex->setMinificationFilter(QOpenGLTexture::Nearest);
    tex->setMagnificationFilter(QOpenGLTexture::Linear);
    tex->setWrapMode(QOpenGLTexture::Repeat);

}
