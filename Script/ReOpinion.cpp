#include "ReOpinion.h"
#include"SDL2_gfxPrimitives.h"
#include<iostream>



ReOpinion::ReOpinion(){
   
    this->player = Player(Vec2(200,200),5,0xffffffff);
    this->enemy = Enemy(Vec2(1920/2,1080/2 - 100),5,0xffff00ff);
    this->x = 0;
    this->hasStateChanged = false;
    this->gMusic = Mix_LoadMUS( "../../Audio/opinion-becomes-fact.wav" );
    this->font = TTF_OpenFont("../../Fonts/Caveat/Caveat-Bold.ttf",60);
    this->text = Text();
 
  
}


void ReOpinion::enemyMove(Enemy enemy){
    this->enemy.vel = Vec2(cos(x*0.002*30),sin(x*0.002*10));
    Enemy e = enemy;
    Enemy e2 = enemy;
    Enemy e3 = enemy;
    Enemy e4 = enemy;
    Enemy e5 = enemy;
    if(x==0){
        Mix_PlayMusic(this->gMusic,-1);
    }
    if(x>0 && x%3==0){
       
       
         this->enemy.particles.push_back(Particle(e4.pos,Vec2(e4.vel.x,e4.vel.y*-1),Vec2(e4.vel.x,e4.vel.y*-1)/60,5,0xffff00ff));
         if(x > 60*6){  
            this->enemy.particles.push_back(Particle(e.pos,e.vel,e.vel/60,5,0xffff00ff));
         }
         if(x>60*12){
            this->enemy.particles.push_back(Particle(e2.pos,e2.vel*-1,(e2.vel*-1)/60,5,0xffff00ff));
         }
         if(x>60*23){
            this->enemy.particles.push_back(Particle(Vec2((x*2)%1920,0),Vec2(0,1),Vec2(0,1)/20,5,0xffff00ff));

         }
         
        
    }    
    if(x>0 && x%8==0){
        if(x>60*51){
            this->enemy.particles.push_back(Particle(Vec2(sin(x*sin(x))*1920,0),Vec2(0,1),Vec2(0,1)/60,5,0xffff00ff));
         }
    }
        
        this->x++;
    
}
void ReOpinion::draw(SDL_Renderer* renderer){
     SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );

    //Clear screen
    SDL_RenderClear( renderer );
    text.drawText(renderer,"Pradadada",Vec2(1920/3,1080/2),{255, 255, 255},this->font);
    text.drawText(renderer,"Valenteen O\'",Vec2(1920/3,1080/3),{255, 255, 255},this->font);

   

    
     


    this->player.draw(renderer);
    this->enemyMove(this->enemy);
    this->enemy.draw(renderer);
    for(int i =this->enemy.particles.size()-1; i >0; i--){
        this->enemy.particles[i].draw(renderer);
        if( this->enemy.particles[i].isOutOfBounds(Vec2(0,0),Vec2(1920,1080))){
            this->enemy.particles.erase(this->enemy.particles.begin()+i);
        }
    }
    
 
    
  
    //Update screen
    SDL_RenderPresent( renderer );
}
