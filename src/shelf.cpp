#include <iostream>
#include <cstdlib>
#include <GL/gl.h>
#include <SDL.h>
#include "header/shelf.h"



void shelf::getShelpCo()
{
    static int x,y;
    static int i = 0;
    SDL_Rect _rect;
    SDL_GetDisplayBounds(0, &_rect);
    SDL_GetMouseState(&x, &y);
    //pos position[2];
//    std::cout<<"function"<<"\n";

    if ( !(pointNum % 2))
    {
        pos2[1] = -(((float) x / (float)_rect.w)*2 - 1);
        pos2[2] = -(((float) y / (float)_rect.h)*2 - 1);


    }
    //checks to see if the i value is and even number
    if ( (pointNum % 2))
    {
        if (drawTrigger == true)
        {

            pos1[1] = -(((float) x / (float)_rect.w)*2 - 1);
            pos1[2] = -(((float) y / (float)_rect.h)*2 - 1);
            draw();
            drawTrigger = false;
            pointsGiven = true;
        }



    }
    //this is triggered if the i is odd

    //std::cout<< pos1[1]<< "    x"<< i <<"\n"<< pos1[2]<< "    y " <<i<<"\n";
    //pos.x = -(((float)x / (float)_rect.w)*2 - 1);
    // = -(((float)y / (float)_rect.h)*2 - 1);






}

void shelf::draw()
{
    if (pointsGiven == true)
    {
        std::cout<<pointNum<<"\n";
        std::cout<< pos1[1]<< "    x1" <<"\n"<< pos1[2]<< "    y1 " <<"\n";
        std::cout<< pos2[1]<< "    x2" <<"\n"<< pos2[2]<< "    y2 " <<"\n";
        glPushMatrix();
        glBegin(GL_LINE_STRIP);
        glColor3f(255.0f,0.0f,0.0f);
        glVertex2d(pos1[1],pos1[2]);
        glVertex2d(pos2[1],pos2[2]);

        glEnd();
        glPopMatrix();
        std::cout<<"draw"<<"\n";
    }
}
