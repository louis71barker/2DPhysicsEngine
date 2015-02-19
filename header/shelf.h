#ifndef SHELF_H__
#define SHELF_H__

//#include <ngl/Vec2.h>



class shelf
{
public:
    float pos1 [3], pos2[3], pointsDrawn;
    int pointNum = 1;

    bool xCoorGained, yCoorGained, coorGained, drawLine, pos1Drawn, pointsGiven;
    bool drawTrigger;

    //shelf(float x, float y) : pos[0].x = x, pos[0].y = y, pos[1].x = x, pos[1].y = y;{}
    void draw();
    void update();
    void trigger();
    void getShelpCo();



protected:

};



#endif
