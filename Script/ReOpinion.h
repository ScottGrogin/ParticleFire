#ifndef REOPINION_H_
#define REOPINION_H_

#include"Enemy.h"
#include"Player.h"
#include"GameStates.h"
#include <SDL.h>

class ReOpinion{
    private:
        int x;
        Enemy enemy;
        Player player;
        

    public:
        GameStates changeState;
        bool hasStateChanged;
        ReOpinion();
        void enemyMove(Enemy enemy);
        void draw(SDL_Renderer* renderer);
};

#endif