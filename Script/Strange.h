#ifndef STRANGE_H_
#define STRANGE_H_
#include"Particle.h"
#include<SDL.h>
#include"GameStates.h"

class Strange{
    private:
        Particle particles[10];
    public:
        GameStates changeState;
        bool hasStateChanged;
        Strange();
        void draw(SDL_Renderer* renderer);
        

};
#endif