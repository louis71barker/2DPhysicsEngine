#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include "header/shelf.h"



void shelf::getShelpCo()
{
    while(!quit)
    {
        SDL_Event e;

        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_MOUSEBUTTONUP)
            {
                if(e.button.button == SDL_BUTTON_LEFT)
                {
                    xCoorGained = true;
                    std::cout<<"button up"<<"/n";
                    //if (xCoorGained == true && yCoorGained == false)
                    {

                    }
                }
            }
        }
    }
}

void shelf::draw()
{
    std::cout<<"draw function"<<"/n";
}
