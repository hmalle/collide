/* 
 *
*/
#include "Balls.hpp"
#include <iostream>
#include <cmath>
#include <SDL.h>

Ball::Ball(){
  x = 0;
  y = 0;
  radius = 1;
  vx = 0;
  vy = 0;
  color = 0x000; //Default to Black
  renderer=NULL;
}

Ball::Ball(SDL_Renderer* _renderer, int _x, int _y, int _r, int _vx, int _vy, uint32_t clr){
  x = _x;
  y = _y;
  radius = _r;
  vx = _vx;
  vy = _vy;
  color = clr;
  renderer = _renderer;
}

int Ball::getX() const{
  return x;
}
int Ball::getY() const{
  return y;
}
int Ball::getVx() const{
  return vx;
}
int Ball::getVy() const{
  return vy;
}
int Ball::getRadius() const{
  return radius;
}
uint32_t Ball::getColor() const{
  return color;
}
void Ball::setX(int _x){
  x = _x;
}
void Ball::setY(int _y){
  y = _y;
}
void Ball::setVx(int _vx){
  vx = _vx;
}
void Ball::setVy(int _vy){
  vy = _vy;
}

void Ball::move(){
  int _x = x + vx; 
  int _y = y + vy; 
  if(_x < 0 || _x > 800)
    setVx(-vx); /* Flip the Velocities directions */
  if(_y <0 || _y> 600)
    setVy(-vy); 
  setX(x+vx);
  setY(y+vy);
}

void Ball::drawCircle() const{
  SDL_SetRenderDrawColor(renderer,0xFF,0x00,0x00,0xFF);  /* RED */
  for(int a=0-radius; a<=radius; a++){
    for(int b=0-radius; b<=radius; b++){
      if(std::pow(a,2)+ std::pow(b,2) <= std::pow(radius,2)){
        SDL_RenderDrawPoint(renderer, x+a, y+b);
      }
    }
  }
}

