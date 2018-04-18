#ifndef GSM_H_
#define GSM_H_
#include"GameStates.h"
#include"ReOpinion.h"
#include"TestBench.h"
#include"DistanceLines.h"
#include"War.h"
#include"Strange.h"
#include<SDL.h>
class GSM{
    private:
        TestBench tb;
        ReOpinion re;
        DistanceLines dl;
        War war;
        Strange strange;
    public:
        GameStates currentState;
        GSM();
        GSM(GameStates initialState);
        void changeState();
        void draw(SDL_Renderer* renderer);

};
#endif