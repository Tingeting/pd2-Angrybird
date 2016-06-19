#ifndef THIRDBIRD_H
#define THIRDBIRD_H

#include <gameitem.h>
#include <bird.h>

#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>


class Thirdbird:public Bird
{
public:
    Thirdbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void SpecialEffect();
};

#endif // THIRDBIRD_H
