#ifndef BARRIER_H
#define BARRIER_H

#include <gameitem.h>

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#include <qdebug.h>

#define Box_DENSITY 20.0f
#define Box_FRICTION 0.8f
#define Box_RESTITUTION 0.2f

class Barrier :public GameItem
{
public:
    Barrier(b2World *world);
    ~Barrier();

    void create_reg(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BARRIER_H
