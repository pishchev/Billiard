#include "powerscale.h"
#include <cmath>
#include <QMatrix4x4>

Powerscale::Powerscale()
{

}

void Powerscale::follow()
{
    QVector3D pos = camera->center + camera->eyeLaser*2;
    pos += -1.95f*camera->rightDir;
    scale[0].model.setTranslate(pos.x() , pos.y(), pos.z());
    pos += -camera->eyeLaser*0.001;

    pos += -camera->headDir*1.065f + camera->headDir*1.065f*2*arrow->force;

    scale[1].model.setTranslate(pos.x() , pos.y(), pos.z());

    float tetta = 180/M_PI*atan2(camera->eyeLaser.y(),sqrt(camera->eyeLaser.x()*camera->eyeLaser.x()+camera->eyeLaser.z()*camera->eyeLaser.z()));
    float alpha = 180/M_PI*atan2(camera->eyeLaser.x(),camera->eyeLaser.z());

    QMatrix4x4 rot;
    rot.rotate(tetta - 90 , camera->rightDir);
    rot.rotate(alpha, QVector3D(0,1,0));

    scale[0].model.rotateMatrix = rot;
    scale[1].model.rotateMatrix = rot;

}
