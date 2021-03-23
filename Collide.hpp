
#ifndef COLLIDE_H
#define COLLIDE_H

#include "Balls.hpp"
#include <vector>
#include <SDL.h>

class Collide{
  private:
    std::vector <Ball*> balls;   
    int size;
    SDL_Renderer ** renderer;
  public:
    Collide();
    Collide(SDL_Renderer** _renderer, int _size);
    ~Collide();
    void update(); 
    void print();
    void collisions();
};

#endif

