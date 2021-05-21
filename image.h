#ifndef IMAGE_H
#define IMAGE_H

#define STB_IMAGE_IMPLEMENTATION
#include <QOpenGLShaderProgram>
#include <string>
#include <QOpenGLTexture>

class Texture
{
public:
    Texture();

    void loadImage(std::string file);

    QOpenGLTexture* tex;

};

#endif // IMAGE_H
