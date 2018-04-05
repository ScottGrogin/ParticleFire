#include"Particle.h"
#include"SDL2_gfxPrimitives.h"

Particle::Particle(Vec2 pos, Vec2 vel, Vec2 acc, float size, Uint32 color){
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
    filledCircleColor(renderer,this->pos.x,this->pos.y,size,color);

}