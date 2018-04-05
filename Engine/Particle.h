#ifndef PARTICLE_H_
#define PARTICLE_H_
#include"Vec2.h"
#include<SDL.h>
class Particle{

    public:
        Vec2 pos, vel, acc;
        float size;
        Uint32 color;
        Particle(Vec2 pos, Vec2 vel, Vec2 acc, float size, Uint32 color);
        void update();
        void draw(SDL_Renderer* renderer);
};
#endif