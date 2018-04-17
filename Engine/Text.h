#ifndef TEST_H_
#define TEST_H_
#include<SDL.h>
#include<SDL_ttf.h>
#include"Vec2.h"
class Text{
    public:
        void drawText(SDL_Renderer* renderer, const char* string, Vec2 pos, SDL_Color color,TTF_Font *font);

};
#endif