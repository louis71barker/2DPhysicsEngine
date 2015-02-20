#include <iostream>
#include <cstdlib>
#include <GL/gl.h>
#include <SDL.h>
#include "header/shelf.h"



void shelf::getShelpCo()
{
    static int x,y;
    SDL_Rect _rect;
    SDL_GetDisplayBounds(0, &_rect);
    SDL_GetMouseState(&x, &y);

    //pos position[2];
//    std::cout<<"function"<<"\n";

    std::cout << _rect.w << " " << _rect.h << "\n";
    if ( !(pointNum % 2))
    {
        pos2[1] = (((float) x * 2.0 / (float)_rect.w)*200.0 - 100);
        pos2[2] = -(((float) y * 2.0 / (float)_rect.w)*200.0 - 100);
        std::cout << pos2[1] << " " << pos2[2] << "\n";


    }
    //checks to see if the i value is and even number
    if ( (pointNum % 2))
    {
        if (drawTrigger == true)
        {

            pos1[1] = (((float) x * 2.0 / (float)_rect.w)*200.0 - 100);
            pos1[2] = -(((float) y * 2.0 / (float)_rect.w)*200.0 - 100);
            pointsDrawn = true;
            std::cout<<"boomboop"<<"\n";




        }



    }
    //this is triggered if the i is odd

    //std::cout<< pos1[1]<< "    x"<< i <<"\n"<< pos1[2]<< "    y " <<i<<"\n";
    //pos.x = -(((float)x / (float)_rect.w)*2 - 1);
    // = -(((float)y / (float)_rect.h)*2 - 1);






}

void shelf::draw()
{
    if (pointsDrawn == true/*pointNum >= 2*/)
    {
        //std::cout<<pointNum<<"\n";
        //std::cout<< pos1[1]<< "    x1" <<"\n"<< pos1[2]<< "    y1 " <<"\n";
        //std::cout<< pos2[1]<< "    x2" <<"\n"<< pos2[2]<< "    y2 " <<"\n";
        glPushMatrix();
        glBegin(GL_LINE_STRIP);

        glColor3f(255.0f,0.0f,0.0f);
        glVertex2f(pos1[1],pos1[2]);
        glVertex2f(pos2[1],pos2[2]);


        glEnd();
        glBegin(GL_POINTS);
                        glPointSize(10);
                        glColor3f(1.0f,0.0f,0.0f);
                        glVertex2f(0.5f,0.5f/*-sXM*pos1[1], sYM*pos1[2]*/);

        glPopMatrix();
        glEnd();
        //std::cout<<"draw"<<"\n";
        //pointNum = 1;
        drawTrigger = false;
    }
}
