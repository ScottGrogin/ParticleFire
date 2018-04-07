#ifndef PARTICLE_H_
#define PARTICLE_H_
#include"Vec2.h"
#include<SDL.h>

class Particle{
    private:
        Vec2 pos;
        void update();

    public:
        Vec2 vel, acc;
        float size;
        Uint32 color;
        Particle(const Vec2& pos, const Vec2& vel, const Vec2& acc, float size, Uint32 color);
        void draw(SDL_Renderer* renderer);
};
#endif