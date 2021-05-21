#include "arrow.h"
#include <cmath>


Arrow::Arrow(Object* obj):followedBy(obj)
{

}

Arrow::Arrow()
{

}

void Arrow::follow()
{
    for(auto it = arrow.begin() ; it!= arrow.end() ; ++it)
        it->model.setTranslate(followedBy->model.tx,
                                 followedBy->model.ty,
                                 followedBy->model.tz);
}

float Arrow::arrowColorFactor()
{
    return force;
}

void Arrow::addRotate(float value)
{
    angle+=value;
    for(auto it = arrow.begin() ; it!= arrow.end() ; ++it)
        it->model.addRotate(value ,0,1,0);
}

float Arrow::prepare()
{
    if (up)
    {
        force+=0.01;
    }
    else
    {
        force-=0.01;
    }

    if (force >=1 )
    {
        up = false;
    }
    if (force <=0 )
    {
        up = true;
    }
}

float Arrow::drop()
{
    force  =0 ;
}

QVector2D Arrow::hit()
{
    return QVector2D(-force * cosf(M_PI/180 * angle),
                     force * sin(M_PI/180 * angle));
}
