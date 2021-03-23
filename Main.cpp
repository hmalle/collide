
//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <iostream>
#include "Collide.hpp"

//Screen dimension constants
#define window_width 800
#define window_height 600

int main( int argc, char* argv[] ){
  if( argc  != 2 ){
    std::cout<<argv[0] <<" <number> \n";
    exit(1);
  }
  int num = atoi(argv[1]);
  if(SDL_Init(SDL_INIT_VIDEO)<0 ){
    std::cout <<"SDL Countnot initialize : "<<SDL_GetError() <<std::endl;
    exit(0);
  }
  SDL_Renderer *renderer = NULL;
  SDL_Window *window = NULL;
  SDL_CreateWindowAndRenderer( window_width, window_height, 0, &window, &renderer);
  if(window==NULL){
    std::cout<<"Error initializing window: "<<SDL_GetError() <<std::endl;
    exit(0);
  }
  /*==============================================================*/
  SDL_SetRenderDrawColor(renderer, 0xFF,0xFF,0xFF,0x3F);
  SDL_RenderClear(renderer);

  /*SDL_Surface *screen = SDL_GetWindowSurface(window);*/
  
  Collide balls = Collide(&renderer, num);

  SDL_Event event; /* Quit */
  bool running = true;
  while (running){
    while(SDL_PollEvent( &event ) ){
      if(event.type == SDL_QUIT){
        running = false;
        break;
      }
    }
    SDL_SetRenderDrawColor(renderer, 0xFF,0xFF,0xFF,0x3F);
    SDL_RenderClear(renderer);
    balls.collisions();
    balls.update();
    SDL_Delay(30);
  }
  
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  return 0;
}

