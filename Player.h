#ifndef PLAYER_H_
#define PLAYER_H_
#include"Vec2.h"
#include<SDL.h>
class Player{
    
    private:
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        int prevKey;
        bool canMoveLeft;
        bool canMoveRight;
        bool canMoveUp;
        bool canMoveDown;
    public:
        Vec2 pos;
        float speed;
        float size;
        Uint32 color;
        Player(const Vec2& pos, float size, Uint32 color);
        void update();
        void draw(SDL_Renderer* renderer);
};

#endif