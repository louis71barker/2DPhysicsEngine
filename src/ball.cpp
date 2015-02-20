#include <iostream>
#include <SDL.h>
#include <cstdlib>

#include "header/scene.h"
#

ball::ball(float x, float y)
{
    //inits the offset
    m_OffX = x;
    m_OffY = y;

    //sets the collision circle size
    m_Collider.r = ball_width /2;

    //inits the Veloity
    m_VelX = 0;
    m_VelY = 0;

    //Move the collider so it stay with the ball
    shiftCollider();
}


void ball::move(SDL_Rect &square, Circle &circle)
{
    //Move the dot left and right
    m_OffX +=m_VelX;
    shiftCollider();

    //if the ball collided or went to far to the left or right
    //if((m_OffX - m_Collider.r < 0) || (m_OffX + m_Collider.r > _rect.))
}



