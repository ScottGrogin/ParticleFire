#include "ReOpinion.h"
#include"SDL2_gfxPrimitives.h"
#include<iostream>


ReOpinion::ReOpinion(){
    this->player = Player(Vec2(200,200),5,0xffffffff);
    this->enemy = Enemy(Vec2(1920/2,1080/2 - 100),5,0xffffffff);
    this->x = 0;
    this->hasStateChanged = false;
    this->gMusic = Mix_LoadMUS( "../../Audio/opinion-becomes-fact.wav" );
    this->roboto = TTF_OpenFont("C:/Users/NULL/Documents/GitHub/ParticleFire/Fonts/Roboto/Roboto-Black.ttf",24);
    this->White = {255, 255, 255};
    this->surfaceMessage = TTF_RenderText_Solid(this->roboto, "put your text here", this->White); 
    this->Message_rect.x = 100;  //controls the rect's x coordinate 
    this->Message_rect.y = 100; // controls the rect's y coordinte
    this->Message_rect.w = 800; // controls the width of the rect
    this->Message_rect.h = 400; // controls the height of the rect
  
}

void ReOpinion::enemyMove(Enemy enemy){
    this->enemy.vel = Vec2(cos(x*0.002*30),sin(x*0.002*10));
    if(x==0){
        Mix_PlayMusic(this->gMusic,-1);
    }
    if(x>0 && x%3==0){
        Enemy e = enemy;
        Enemy e2 = enemy;
        Enemy e3 = enemy;
        Enemy e4 = enemy;
        Enemy e5 = enemy;
       
         this->enemy.particles.push_back(Particle(e4.pos,Vec2(e4.vel.x,e4.vel.y*-1),Vec2(e4.vel.x,e4.vel.y*-1)/60,5,0xffff00ff));
        
    }    
        
        this->x++;
    
}
void ReOpinion::draw(SDL_Renderer* renderer){
     SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );

    //Clear screen
    SDL_RenderClear( renderer );

    this->Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
     

    SDL_RenderCopy(renderer, this->Message, NULL, &this->Message_rect); 

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