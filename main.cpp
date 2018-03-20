#include"Engine/WindowSetup.h"
#include"SDL2_gfxPrimitives.h"
#include<SDL.h>
void draw(SDL_Renderer*, float delta);

int main(int argc, char *argv[]){
    WindowSetup windowSetup(1920,1080,60,true,draw);

    return 0;
}


void draw(SDL_Renderer* renderer, float delta){
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
    //Clear screen
    SDL_RenderClear( renderer );


    filledCircleColor(renderer,100,100,50,0xff00ffff);
  
    //Update screen
    SDL_RenderPresent( renderer );
      
}