#ifndef POWERSCALE_H
#define POWERSCALE_H
#include "object.h"
#include "quadMesh.h"
#include "arrow.h"
#include "camera.h"
class Powerscale
{
public:
    Powerscale();

    void follow();

    std::vector<Object> scale;

    Camera* camera;
    Arrow* arrow;

};

#endif // POWERSCALE_H
