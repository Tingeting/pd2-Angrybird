#include "thirdbird.h"

Thirdbird::Thirdbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
    :Bird(x,y,radius,timer,pixmap,world,scene)
{

}

void Thirdbird::SpecialEffect(){

    g_body->SetLinearVelocity(b2Vec2(0.01,-100));
}

