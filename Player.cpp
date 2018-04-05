#include"Player.h"
#include"SDL2_gfxPrimitives.h"


Player::Player(const Vec2& pos, float size, Uint32 color){
    this->pos = pos;
    this->size = size;
    this->color = color;
    this->speed = 7;
    this->canMoveLeft=true;
    this->canMoveRight=true;
    this->canMoveUp =true;
    this->canMoveDown = true;
}

void Player::update(){
    if(keystate[SDL_SCANCODE_LSHIFT]){
        this->speed = 3;
    } else {
        speed =7;
    }
    //LR movement
    if(keystate[SDL_SCANCODE_LEFT]&&canMoveLeft){
       if(prevKey == SDL_SCANCODE_RIGHT){
           canMoveRight=false;
       }

        prevKey = SDL_SCANCODE_LEFT;
        this->pos.x-=speed;
     
    }

    if(keystate[SDL_SCANCODE_RIGHT]&&canMoveRight){
        if(prevKey == SDL_SCANCODE_LEFT){
            canMoveLeft=false;
        }

        prevKey = SDL_SCANCODE_RIGHT;
        this->pos.x+=speed;  
   }

     if(!keystate[SDL_SCANCODE_RIGHT]||!keystate[SDL_SCANCODE_LEFT]){
            canMoveRight = true;
            canMoveLeft=true;
        }

    //UD movement
    if(keystate[SDL_SCANCODE_UP]&&canMoveUp){
       if(prevKey == SDL_SCANCODE_DOWN){
           canMoveDown=false;
       }

        prevKey = SDL_SCANCODE_UP;
        this->pos.y-=speed;
     
    }

    if(keystate[SDL_SCANCODE_DOWN]&&canMoveDown){
        if(prevKey == SDL_SCANCODE_UP){
            canMoveUp=false;
        }

        prevKey = SDL_SCANCODE_DOWN;
        this->pos.y+=speed;  
   }

     if(!keystate[SDL_SCANCODE_DOWN]||!keystate[SDL_SCANCODE_UP]){
            canMoveDown = true;
            canMoveUp=true;
        }
    
            

}

void Player::draw(SDL_Renderer* renderer){
    filledCircleColor(renderer,this->pos.x,this->pos.y,size,color);

}