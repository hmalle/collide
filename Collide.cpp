
#include "Collide.hpp"
#include <vector>
#include <iostream>
#include <time.h>

Collide::Collide(){
  /* DEFAULT CONSTRUCTOR */
  size = 0;
}

Collide::~Collide(){
  /*
  for(int a=size-1; a>=0; a--){
    delete balls[a];
    balls.pop_back();
  }
  */
}
 
//std::vector <Ball*> balls;   
Collide::Collide(SDL_Renderer** _renderer, int _size){
  /* Initialize how many elements */
  srand(time(NULL));
  int _x,_y,_vx,_vy,_r;
  size = _size;
  renderer = _renderer;
  for(int a=0; a < size; a++){
    /*Populate the screen */
    _r = 10;
    _x = rand()%(800-_r) + _r;
    _y = rand()%(600-_r) + _r;
    _vx = 5- (rand()%10 + 1);
    _vy = 5- (rand()%10 + 1);
    balls.push_back(new Ball(*renderer, _x,_y,_r,_vx,_vy,0x0));
  }
}

void Collide::print(){
  std::cout<<"Size is : "<< size<<std::endl;
  for(int a=0; a<size; a++){
    std::cout<<balls[a]->getX()<<std::endl;
    std::cout<<balls[a]->getY()<<std::endl;
    std::cout<<balls[a]->getVx()<<std::endl;
    std::cout<<balls[a]->getVy()<<std::endl;
    std::cout<<balls[a]->getRadius()<<std::endl;
    std::cout<<"================================"<<std::endl;
  }
}

void Collide::update(){
  for(int a=0; a<size; a++){
    balls[a]->move();
    balls[a]->drawCircle();
  }
  SDL_RenderPresent(*renderer);
}

void Collide::collisions(){
  int xa,xb,ya,yb,dist,tmp;
  for(int a=0; a<size; a++){
    for(int b=a+1; b<size; b++){
      xa = balls[a]->getX();
      xb = balls[b]->getX();
      ya = balls[a]->getY();
      yb = balls[b]->getY();
      dist = balls[a]->getRadius()+balls[b]->getRadius();
      if(dist>abs(xa-xb) && dist>abs(ya-yb)){
        tmp = balls[a]->getVx();
        balls[a]->setVx(balls[b]->getVx());
        balls[b]->setVx(tmp);
        tmp = balls[a]->getVy();
        balls[a]->setVy(balls[b]->getVy());
        balls[b]->setVy(tmp);
      }
    }
  }
}
