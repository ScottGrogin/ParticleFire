#include"Particle.h"
#include"SDL2_gfxPrimitives.h"


Particle::Particle(const Vec2& pos, const Vec2& vel, const Vec2& acc, float size, Uint32 color){
    this->pos = pos;
    this->vel = vel;
    this->acc = acc;
    this->size = size;
    this->color = color;
}
void Particle::update(){
    this->pos += this->vel;
    this->vel += this->acc;
}

void Particle::draw(SDL_Renderer* renderer){
    update();
    filledCircleColor(renderer,this->pos.x,this->pos.y,size,color);

}

bool Particle::isOutOfBounds(Vec2 min, Vec2 max){
    
    if(this->pos.x-this->size > max.x || this->pos.x+this->size < min.x||this->pos.y-this->size > max.y || this->pos.y+this->size < min.y )  {
        return true;
    }
    return false;
}