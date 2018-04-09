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

    plr.draw(renderer);
    eTst.draw(renderer,enemyMove);
    for(int i =eTst.particles.size()-1; i >0; i--){
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
    enemy->vel = Vec2(cos(x*0.002*30),sin(x*0.002*10));
    if(x>0 && x%2==0){
        Enemy e = *enemy;
        Enemy e2 = *enemy;
        Enemy e3 = *enemy;
        Enemy e4 = *enemy;
        Enemy e5 = *enemy;
       
        
        enemy->particles.push_back(Particle(e.pos,e.vel,e.vel/60,5,0xffff00ff));
        enemy->particles.push_back(Particle(e2.pos,e2.vel*-1,(e2.vel*-1)/60,5,0xffff00ff));
        enemy->particles.push_back(Particle(e3.pos,Vec2(e3.vel.x*-1,e3.vel.y),Vec2(e3.vel.x*-1,e3.vel.y)/60,5,0xffff00ff));
        enemy->particles.push_back(Particle(e4.pos,Vec2(e4.vel.x,e4.vel.y*-1),Vec2(e4.vel.x,e4.vel.y*-1)/60,5,0xffff00ff));
        
    }    
        
        x++;
    
}