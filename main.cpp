#include"WindowSetup.h"
#include<SDL.h>
#include"TestBench.h"

TestBench tb;
void draw(SDL_Renderer* renderer,float delta);

int main(int argc, char *argv[]){
    WindowSetup windowSetup(1920,1080,60,true,draw);
    tb = TestBench();

    return 0;
}


void draw(SDL_Renderer* renderer, float delta){
    tb.draw(renderer);

}
