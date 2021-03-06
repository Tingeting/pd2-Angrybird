#ifndef SHOOTER_H
#define SHOOTER_H

#include <gameitem.h>
#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#include <qdebug.h>

#define shooter_x 3.4f
#define shooter_y 6.0f

class Shooter :public GameItem
{
    public:
    Shooter(int x, int y, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

    void waiting(Bird *bird);
};

#endif // SHOOTER_H

