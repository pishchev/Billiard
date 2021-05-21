#ifndef GETTINGBALLS_H
#define GETTINGBALLS_H

#include "object.h"
#include "sphere.h"
#include "camera.h"

class GettingBalls
{
public:
    GettingBalls();

    void follow();

    std::vector<Object> balls = {};

    Camera* camera;

};

#endif // GETTINGBALLS_H
