#include"Enemy.h"
#include"SDL2_gfxPrimitives.h"

Enemy::Enemy(const Vec2& pos, float size, Uint32 color){
    this->pos = pos;
    this->size = size;
    this->color = color;
    this->acc = Vec2(0,0);
    this->vel = Vec2(0,0);
}

void Enemy::update(){
    this->pos += this->vel;
    this->vel += this->acc;
}

void Enemy::draw(SDL_Renderer* renderer, void(*pattern)(Enemy*)){
    update();
    pattern(this);
    filledCircleColor(renderer,this->pos.x,this->pos.y,size,color);
}

