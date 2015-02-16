#ifndef SHELF_H__
#define SHELF_H__

#include <ngl/Vec2.h>



class shelf
{
public:
    static float pos1, pos2;
    static bool xCoorGained, yCoorGained;

    void draw();
    void update();
    void trigger();
    void getShelpCo();


protected:
    ngl::Vec2 m_pos;

};



#endif
