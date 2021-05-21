#ifndef BALL_H
#define BALL_H

#include "object.h"

class Ball
{
public:
    Ball();
    Ball(Object obj , int number , float radius);

    void render(QOpenGLShaderProgram *m_program ,QOpenGLFunctions* scene);

    void move();

    void toPreviousState();
    void savePreviousState();

    void hit(float adx , float ady);
    void rotate();

    static bool collisionBalls(Ball& b1 , Ball& b2);
    static bool collisionWalls(Ball& b1);

    float collideBallLoss = 0.05f;
    float collideTableLoss = 0.15f;
    float frictionLoss = 0.0001f;

    float dx = 2;
    float dz = 2;

    float radius = 1.0f;

    float prevX = 0;
    float prevY = 0;

    Object obj;
    int number;
};

class BallsPool
{
public:
    BallsPool();

    void addBall(int number, Ball ball);

    void trianglePosition();

    void move();

    void render(QOpenGLShaderProgram *m_program ,QOpenGLFunctions* scene);

    std::map<int , Ball> balls = {};
};

#endif // BALL_H
