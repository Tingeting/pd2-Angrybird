#include "shooter.h"

Shooter::Shooter(int x, int y, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setPos(x,y);
    scene->addItem(&g_pixmap);
}

void Shooter::waiting(Bird *bird){

    bird->g_body->SetTransform(b2Vec2(shooter_x,shooter_y),0);

}
