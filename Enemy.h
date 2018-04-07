#ifndef ENEMY_H_
#define ENEMY_H_
#include"Vec2.h"
#include<SDL.h>

class Enemy{
    private:
        Vec2 pos;
        void update();

    public:
        Vec2 vel, acc;
        float size;
        Uint32 color;
        Enemy(const Vec2& pos, float size, Uint32 color);
        void draw(SDL_Renderer* renderer, void(*pattern)(Enemy*));
};
#endif