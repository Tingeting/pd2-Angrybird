#ifndef BG_H
#define BG_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#include <qdebug.h>

class Bg:public GameItem
{
public:
    Bg(int x, int y, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BG_H



