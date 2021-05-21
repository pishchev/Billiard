#include "ball.h"
#include <cmath>
#include <algorithm>

Ball::Ball()
{

}

void Ball::hit(float adx , float ady)
{
    dx += adx;
    dz += ady;
}

Ball::Ball(Object obj , int number , float radius): obj(obj),number(number), radius(radius)
{
    prevX = obj.model.tx;
    prevY = obj.model.tz;
    dx = 0;
    dz = 0;
};

float angle(float x, float y)
{
    QVector2D vecX(1,0);

    QVector2D v1(x, y);

    v1.normalize();

    float dot_ = QVector2D::dotProduct(vecX , v1);
    float n = vecX.length() * v1.length();

    float r= -1;
    if (v1.y() < 1)
    {
        r = 1;
    }

    return r*acos(dot_/n);
}

bool Ball::collisionBalls(Ball& b1 , Ball& b2)
{
    if (b1.number == b2.number)return true;

    float x1 = b1.obj.model.tx;
    float x2 = b2.obj.model.tx;
    float y1 = b1.obj.model.tz;
    float y2 = b2.obj.model.tz;

    float Dx = x1 - x2;
    float Dy = y1 - y2;

    float d = sqrt(Dx*Dx+Dy*Dy); if (d == 0) d = 0.01;
    float r1 = b1.radius;
    float r2 = b2.radius;

    if (d > r1+r2) return true;


    float s = Dx/d; // sin
    float e = Dy/d; // cos

    float dx1 = b1.dx;
    float dx2 = b2.dx;
    float dy1 = b1.dz;
    float dy2 = b2.dz;

    float Vn1 = dx2*s + dy2*e;
    float Vn2 = dx1*s + dy1*e;
    float dt = (r2+r1-d)/(Vn1-Vn2);
    if (dt > 0.01) dt = 0.01;
    if (dt < -0.01) dt = -0.01;
    Dx = x1 - x2;
    Dy = y1 - y2;
    d = sqrt(Dx*Dx+Dy*Dy); if (d == 0) d = 0.01;
    s = Dx/d; // sin
    e = Dy/d; // cos
    Vn1 = dx2*s + dy2*e;
    Vn2 = dx1*s + dy1*e;
    float Vt1 = -dx2*e+dy2*s;
    float Vt2 = -dx1*e+dy1*s;

    float o = Vn2;
    Vn2 = Vn1;
    Vn1 = o;

    b1.dx = Vn2*s-Vt2*e;
    b1.dz = Vn2*e+Vt2*s;
    b2.dx = Vn1*s-Vt1*e;
    b2.dz = Vn1*e+Vt1*s;

    b1.dx *= (1-b1.collideBallLoss);
    b1.dz *= (1-b1.collideBallLoss);
    b2.dx *= (1-b2.collideBallLoss);
    b2.dz *= (1-b2.collideBallLoss);

    return false;

}

bool Ball::collisionWalls(Ball& b1)
{
    if (b1.obj.model.tx >= 14.2 - b1.radius || b1.obj.model.tx <= -14.2 + b1.radius)
    {
        b1.dx = -b1.dx;
        b1.dx *= (1-b1.collideTableLoss);
        return false;
    }
    if (b1.obj.model.tz >= 27.6 - b1.radius || b1.obj.model.tz <= -27.6 + b1.radius)
    {
        b1.dz = -b1.dz;
        b1.dz *= (1-b1.collideTableLoss);
        return false;
    }
    return true;
}

void Ball::move()
{
    obj.model.tx +=dx;
    obj.model.tz +=dz;
}

void Ball::rotate()
{
    obj.model.addRotate(50*sqrt(dx*dx+dz*dz) , dz , 0, -dx);
}

void Ball::toPreviousState()
{
    obj.model.tx = prevX;
    obj.model.tz = prevY;
}

void Ball::savePreviousState()
{
    prevX = obj.model.tx;
    prevY = obj.model.tz;

    dx *= (1- std::fmin(frictionLoss/abs(dx) , 1)) ;
    dz *= (1-std::fmin(frictionLoss/abs(dz) , 1));
}

void Ball::render(QOpenGLShaderProgram *m_program ,QOpenGLFunctions* scene)
{
    obj.render(m_program ,scene);

}

BallsPool::BallsPool()
{

};

void BallsPool::addBall(int number, Ball ball)
{
    balls.emplace(number, ball);
};

void BallsPool::render(QOpenGLShaderProgram *m_program ,QOpenGLFunctions* scene)
{
    for (auto it = balls.begin() ; it!= balls.end() ; ++it)
    {
        it->second.render(m_program,scene);
    }
}

void BallsPool::move()
{
    for (auto it = balls.begin() ; it!= balls.end() ; ++it)
    {
        bool moveAccess = true;
        it->second.move();

        for (auto it2 = balls.begin(); it2!= balls.end() ; ++it2)
        {
            //moveAccess &= Ball::collisionBalls(it->second , it2->second);
            if (!Ball::collisionBalls(it->second , it2->second))
            {
                moveAccess = false;
            }
        }
        if (!Ball::collisionWalls(it->second))
        {
            it->second.rotate();
            moveAccess = false;
        }

        if (moveAccess)
        {
            it->second.rotate();
            it->second.savePreviousState();
        }
        else
        {
            it->second.toPreviousState();
        }

    }
}

void BallsPool::trianglePosition()
{
    int activeBall = 1;
    float radius = balls[0].radius+0.01f;
    for (int i = 0 ; i < 5 ; i ++)
    {
        for (int k = 0 ; k <= i ; k ++)
        {
            balls[activeBall].obj.model.setTranslate(-i*radius+2*k*radius,
                                                     6.6f,
                                                     -13 - sqrt(3)*i*radius- 0.01 );
            activeBall++;
        }
    }
    balls[0].obj.model.setTranslate(0,6.6f,8);
}
