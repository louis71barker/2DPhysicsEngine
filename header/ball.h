#ifndef BALL_H__
#define BALL_H__

#include <SDL.h>
//#include <ngl/Vec2.h>


struct Circle
{
    float x,y;
    float r;
};


class ball
{
public:

    //circle collision detection
    bool checkCollision (Circle& a, Circle& b);

    //ball on shelf collision detection
    bool checkCollision(Circle& a, SDL_Rect& b);

    //Calculates the distance squared between the points
    double distanceSquared(float x1, float y1, float x2, float y2);


    //dimensions of the ball
    const int ball_width = 20;
    const int ball_height = 20;

    //maximum velocity of the ball
    const int ball_vel = 1;

    //intis the variables
    ball (float x, float y);
    //takes the button press to determine were the ball will appear from on screen
    void eventHandle ( SDL_Event e );

    //applies the gravity to the dot and checks for collision
    void move (SDL_Rect& square, Circle& circle);

    //Shows the ball on the screen when the right mouse button is pressed
    void draw();

    //gets collisons cirlces
    Circle& getCollider();

private:
    //the x and y ofset of the ball
    float m_OffX, m_OffY;

    // the velocity of the ball
    float m_VelX, m_VelY;

    //the balls collisons circle
    Circle m_Collider;

    //this moves the collions circle in relivence to the actaul ball
    void shiftCollider();


protected:
//    ngl::Vec2 m_pos;

};



#endif
