#ifndef ENEMY_H_
#define ENEMY_H_
#include"Vec2.h"
#include <vector>
#include"Particle.h"
#include<SDL.h>

class Enemy{
    private:
        void update();

    public:
        Vec2 vel, acc,pos;
        std::vector<Particle> particles;
        float size;
        Uint32 color;
        Enemy();
        Enemy(const Vec2& pos, float size, Uint32 color);
        void draw(SDL_Renderer* renderer);
};
#endif