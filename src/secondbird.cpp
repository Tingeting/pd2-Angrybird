#include "secondbird.h"

Secondbird::Secondbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
    :Bird(x,y,radius,timer,pixmap,world,scene)
{

}

void Secondbird::SpecialEffect(){

     g_body->SetLinearVelocity(b2Vec2(-50,-50));
}


