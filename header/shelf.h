#ifndef SHELF_H__
#define SHELF_H__

//#include <ngl/Vec2.h>



class shelf
{
public:
    float pos1, pos2;
    bool xCoorGained, yCoorGained;

    void draw();
    void update();
    void trigger();
    void getShelpCo();


protected:

};



#endif
