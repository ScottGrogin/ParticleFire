#include "ReOpinion.h"
#include"SDL2_gfxPrimitives.h"
#include<iostream>

ReOpinion::ReOpinion(){
    this->player = Player(Vec2(200,200),5,0xffffffff);
    this->enemy = Enemy(Vec2(1920/2,1080/2 - 100),5,0xffffffff);
    this->x = 0;
}

void ReOpinion::enemyMove(Enemy enemy){
    this->enemy.vel = Vec2(cos(x*0.002*30),sin(x*0.002*10));
    if(x>0 && x%3==0){
        Enemy e = enemy;
        Enemy e2 = enemy;
        Enemy e3 = enemy;
        Enemy e4 = enemy;
        Enemy e5 = enemy;
       
        
        //this->enemy.particles.push_back(Particle(e.pos,e.vel,e.vel/60,5,0xffff00ff));
       //this->enemy.particles.push_back(Particle(e2.pos,e2.vel*-1,(e2.vel*-1)/60,5,0xffff00ff));
        //this->enemy.particles.push_back(Particle(e3.pos,Vec2(e3.vel.x*-1,e3.vel.y),Vec2(e3.vel.x*-1,e3.vel.y)/60,5,0xffff00ff));
        this->enemy.particles.push_back(Particle(e4.pos,Vec2(e4.vel.x,e4.vel.y*-1),Vec2(e4.vel.x,e4.vel.y*-1)/60,5,0xffff00ff));
        
    }    
        
        this->x++;
    
}
void ReOpinion::draw(SDL_Renderer* renderer){
     SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );

    //Clear screen
    SDL_RenderClear( renderer );

    this->player.draw(renderer);
    this->enemyMove(this->enemy);
    this->enemy.draw(renderer);
    for(int i =this->enemy.particles.size()-1; i >0; i--){
        this->enemy.particles[i].draw(renderer);
        if( this->enemy.particles[i].isOutOfBounds(Vec2(0,0),Vec2(1920,1080))){
            this->enemy.particles.erase(this->enemy.particles.begin()+i);
        }
    }
    std::cout<< this->enemy.particles.size()<<std::endl;
 
    
  
    //Update screen
    SDL_RenderPresent( renderer );
}