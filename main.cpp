#include"Engine/WindowSetup.h"
#include"SDL2_gfxPrimitives.h"
#include"Vec2.h"
#include"Particle.h"
#include"Player.h"
#include<SDL.h>
void draw(SDL_Renderer*, float delta);

Particle pTst(Vec2(100,100),Vec2(1,0),Vec2(0.5,0),10,0xff00ffff);
Player plr(Vec2(200,200),5,0xffffffff);

int main(int argc, char *argv[]){
    WindowSetup windowSetup(1920,1080,60,true,draw);

    return 0;
}


void draw(SDL_Renderer* renderer, float delta){
    SDL_RenderSetLogicalSize(renderer,1920,1080);
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
    //Clear screen
    SDL_RenderClear( renderer );

    pTst.update();
    pTst.draw(renderer);
    plr.update();
    plr.draw(renderer);
    
  
    //Update screen
    SDL_RenderPresent( renderer );
      
}