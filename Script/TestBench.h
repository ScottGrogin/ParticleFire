#ifndef TSTBNCH_H_
#define TSTBNCH_H_

#include"Enemy.h"
#include"Player.h"
#include"GameStates.h"
#include <SDL.h>

class TestBench{
    private:
        int x;
        Enemy enemy;
        Player player;
        

    public:
        GameStates changeState;
        bool hasStateChanged;
        TestBench();
        void enemyMove(Enemy enemy);
        void draw(SDL_Renderer* renderer);
};

#endif