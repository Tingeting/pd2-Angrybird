#ifndef FIRSTBIRD_H
#define FIRSTBIRD_H

#include <gameitem.h>
#include <bird.h>

#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

class Firstbird:public Bird
{
public:
    Firstbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void SpecialEffect();
};

#endif // FIRSTBIRD_H
