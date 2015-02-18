#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "header/shelf.h"



void SDLErrorExit(const std::string &_err)
{
    std::cerr<<_err<<"\n";
    std::cerr<<SDL_GetError()<<"/n";
    SDL_Quit();
    exit(EXIT_FAILURE);
}

SDL_GLContext createOpenGLContext(SDL_Window *_win)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

    return SDL_GL_CreateContext(_win);
}

void windowOps()
{
    //error checking sdl loading
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        SDLErrorExit("Unable to init SDL");
    }

    //grabs the screen size
    SDL_Rect rect;
    SDL_GetDisplayBounds(0,&rect);
    SDL_Window *win;
    win=SDL_CreateWindow("2D Phyics engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, rect.w/2, rect.h/2, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    shelf s;

   //error checking to make sure window is available to be opened
    if (!win)
    {
        SDLErrorExit("Unable to create window");
    }

    SDL_GLContext gl=createOpenGLContext(win);
    if(!gl)
    {
        SDLErrorExit("Problem creating OpenGL context");
    }
    SDL_GL_MakeCurrent(win,gl);
    SDL_GL_SetSwapInterval(1);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f,(float) rect.w/rect.h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0,0,2,0,0,0,0,1,0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glClearColor( 255, 255 ,255, 1 );

    int quit = 0;
    while(!quit)
    {
        SDL_Event e;

        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_WINDOWEVENT :
                {
                  int w, h;
                  SDL_GetWindowSize(win, &w, &h);
                  glViewport(0, 0, w, h);
                }
                break;

            case SDL_QUIT: quit = 1;break;
                case SDL_KEYDOWN :
                {
                    switch(e.key.keysym.sym)
                    {
                    case SDLK_ESCAPE : quit = 1; break;
                    case SDLK_w : glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                    case SDLK_s : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                    }
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                {
                    if(e.button.button == SDL_BUTTON_LEFT)
                    {
                        s.xCoorGained = true;

                        if (s.xCoorGained == true && s.yCoorGained == false)
                        {
                            s.yCoorGained = true;

                        }
                        if (s.xCoorGained == true && s.yCoorGained == true)
                        {
                            s.coorGained = true;
                            s.drawTrigger = true;
                            s.pointNum++;
                            s.getShelpCo();
                            std::cout<<"boom coor"<<"\n";

                        }
                    }
                 }
                break;

            }

        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        SDL_GL_SwapWindow(win);
    }

}
