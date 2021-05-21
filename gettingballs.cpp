#include "gettingballs.h"
#include <cmath>

GettingBalls::GettingBalls()
{

}

void GettingBalls::follow()
{
    for (int i = 0 ; i < balls.size() ; i ++)
    {
        QVector3D pos = camera->center + camera->eyeLaser*2;
        pos += (1.95f - i*0.12) *camera->rightDir;
        pos += camera->headDir*1.065f;
        balls[i].model.setTranslate(pos.x() , pos.y(), pos.z());


        float tetta = 180/M_PI*atan2(camera->eyeLaser.y(),sqrt(camera->eyeLaser.x()*camera->eyeLaser.x()+camera->eyeLaser.z()*camera->eyeLaser.z()));
        float alpha = 180/M_PI*atan2(camera->eyeLaser.x(),camera->eyeLaser.z());

        QMatrix4x4 rot;
        rot.rotate(tetta , camera->rightDir);
        rot.rotate(alpha, QVector3D(0,1,0));

        //balls[i].model.rotateMatrix = rot;

    }
}
