#include"Engine/WindowSetup.h"
#include"SDL2_gfxPrimitives.h"
#include"Vec2.h"
#include"Particle.h"
#include<SDL.h>
void draw(SDL_Renderer*, float delta);

Particle pTst(Vec2(100,100),Vec2(1,0),Vec2(0.1,0),10,0xff00ffff);

int main(int argc, char *argv[]){
    WindowSetup windowSetup(1920,1080,60,true,draw);

    return 0;
}


void draw(SDL_Renderer* renderer, float delta){
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
    //Clear screen
    SDL_RenderClear( renderer );

    pTst.update();
    pTst.draw(renderer);
    
  
    //Update screen
    SDL_RenderPresent( renderer );
      
}