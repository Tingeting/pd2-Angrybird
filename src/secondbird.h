#ifndef SECONDBIRD_H
#define SECONDBIRD_H

#include <gameitem.h>
#include <bird.h>

#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>


class Secondbird:public Bird
{
public:
    Secondbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void SpecialEffect();
};

#endif // SECONDBIRD_H
