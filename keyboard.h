#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QOpenGLShaderProgram>
#include <QOpenGLExtraFunctions>
#include <QColorDialog>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <map>

struct KeyBoard
{
    std::map<int , bool> keys = {{Qt::Key_A , false},
                                {Qt::Key_D , false},
                                {Qt::Key_S , false},
                                {Qt::Key_W , false},
                                {Qt::Key_Space , false},
                                {Qt::Key_Control , false},
                                {Qt::Key_Up , false},
                                {Qt::Key_Left , false},
                                {Qt::Key_Right , false},
                                {Qt::Key_Down , false},
                                {Qt::Key_1 , false},
                                {Qt::Key_0 , false},
                                {Qt::Key_E , false},
                                {Qt::Key_X , false},
                                {Qt::Key_Z , false}};
};

#endif // KEYBOARD_H
