#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "gameitem.h"
#include "bird.h"

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>

#define launch_x 3.8f
#define launch_y 4.5f

class Launcher : public GameItem
{
    public:
        Launcher(int x, int y, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
        void ReadyToShoot(Bird *bird);
};
endif // LAUNCHER_H
