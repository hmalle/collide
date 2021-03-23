
#ifndef _BALL_H
#define _BALL_H

#include <SDL.h>

class Ball{
  private:
    int vx; /* Velocity in X Direction */
    int vy; /* Velocity in y component */
    int radius;
    int x;
    int y;
    uint32_t color;
    SDL_Renderer * renderer;
  public:
    Ball();
    Ball(SDL_Renderer* _renderer,int _x,int _y,int _r,int _vx,int _vy,uint32_t clr);

    int getX() const;
    int getY() const;
    int getVx() const;
    int getVy() const;
    int getRadius() const;
    uint32_t getColor() const;

    void setX(int _x);
    void setY(int _y);
    void setVx(int _vx);
    void setVy(int _vy);
    void drawCircle()const;
    void move(); 
};

#endif

