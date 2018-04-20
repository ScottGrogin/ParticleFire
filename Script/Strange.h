#ifndef STRANGE_H_
#define STRANGE_H_
#include"Particle.h"
#include<SDL.h>
#include"GameStates.h"

class Strange{
    private:
        Particle particle;
        //Particle particles[10] =NULL;
    public:
        GameStates changeState;
        bool hasStateChanged;
        Strange();
        void draw(SDL_Renderer* renderer);
        

};
#endif