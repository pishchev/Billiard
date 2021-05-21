#ifndef ARROW_H
#define ARROW_H
#include "object.h"

class Arrow
{
public:
    Arrow();
    Arrow(Object* obj);
    void follow();
    float arrowColorFactor();

    QVector2D hit();

    float drop();

    float prepare();

    void addRotate(float value);

    bool up = true;
    bool preparing = false;
    bool shot = false;

    float angle = 270.0f;

    float force = 0.0f;

    std::vector<Object> arrow;
    Object* followedBy;
};

#endif // ARROW_H
