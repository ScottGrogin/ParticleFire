#include"Engine/WindowSetup.h"
#include"SDL2_gfxPrimitives.h"
#include"Vec2.h"
#include"Particle.h"
#include"Player.h"
#include"Enemy.h"
#include<SDL.h>
#include<iostream>

void draw(SDL_Renderer*, float delta);
void enemyMove(Enemy*);
int x =0;

Particle pTst(Vec2(100,100),Vec2(1,0),Vec2(0.5,0),10,0xff0000ff);
Enemy eTst(Vec2(1920/2,1080/2 - 100),5,0xffffffff);
Player plr(Vec2(200,200),5,0xffffffff);


int main(int argc, char *argv[]){
    WindowSetup windowSetup(1920,1080,60,true,draw);

    return 0;
}


void draw(SDL_Renderer* renderer, float delta){
   
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );

    //Clear screen
    SDL_RenderClear( renderer );

    pTst.draw(renderer);
    plr.draw(renderer);
    eTst.draw(renderer,enemyMove);
    for(int i =0; i < eTst.particles.size();i++){
        eTst.particles[i].draw(renderer);
        if( eTst.particles[i].isOutOfBounds(Vec2(0,0),Vec2(1920,1080))){
            eTst.particles.erase(eTst.particles.begin()+i);
        }
    }
    std::cout<< eTst.particles.size()<<std::endl;
 
    
  
    //Update screen
    SDL_RenderPresent( renderer );
      
}

void enemyMove(Enemy* enemy){
    enemy->vel = Vec2(cos(x*0.002*30)*15+cos(x*5),sin(x*0.002*30)*15);
    
    enemy->particles.push_back(Particle(enemy->pos,enemy->vel,Vec2(0,0),5,0xffff00ff));
    
    x++;
}