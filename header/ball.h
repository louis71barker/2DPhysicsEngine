#ifndef BALL_H__
#define BALL_H__

#include "src/ball.cpp"
#include <ngl/Vec2.h>




class ball
{
public:
    float pos1;

    void draw();
    void update();
    void trigger();
    void getPos();

protected:
    ngl::Vec2 m_pos;

};



#endif
