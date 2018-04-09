#ifndef REOPINION_H_
#define REOPINION_H_

#include"Enemy.h"
#include"Player.h"
#include <SDL.h>

class ReOpinion{
    private:
        int x;
        Enemy enemy;
        Player player;
        

    public:
        ReOpinion();
        void enemyMove(Enemy enemy);
        void draw(SDL_Renderer* renderer);
};

#endif