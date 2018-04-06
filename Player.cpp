#include"Player.h"
#include"SDL2_gfxPrimitives.h"


Player::Player(const Vec2& pos, float size, Uint32 color){
    this->pos = pos;
    this->size = size;
    this->color = color;
    this->speed = 6;
    this->canMoveLeft=true;
    this->canMoveRight=true;
    this->canMoveUp =true;
    this->canMoveDown = true;
}

void Player::update(){
    if(keystate[SDL_SCANCODE_LSHIFT]){
        this->speed = 3;
    } else {
        speed =6;
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
    
    //TODO:Proper Screen Scaling to have resolution independant coordinate system.

    if(this->pos.x-this->size > 1920)  {
        this->pos.x =0;
    }
    if(this->pos.x+this->size < 0)  {
        this->pos.x =1920;
    }

    if(this->pos.y-this->size > 1080)  {
        this->pos.y =0;
    }
    if(this->pos.y+this->size < 0)  {
        this->pos.y =1080;
    }
}

void Player::draw(SDL_Renderer* renderer){
    filledCircleColor(renderer,this->pos.x,this->pos.y,size,color);

}