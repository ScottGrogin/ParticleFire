#include"WindowSetup.h"
#include<SDL.h>
#include"GameStates.h"
#include"GSM.h"

GSM gsm;
void draw(SDL_Renderer* renderer,float delta);

int main(int argc, char *argv[]){
    WindowSetup windowSetup(1920,1080,60,true,draw);
    gsm = GSM(GameStates::TEST_BENCH);

    return 0;
}


void draw(SDL_Renderer* renderer, float delta){
    
    gsm.draw(renderer);

}
