#ifndef WINDOW_SETUP_H_
#define WINDOW_SETUP_H_
#include<SDL.h>
class WindowSetup{
    public:
        WindowSetup(int width, int height, int fps, bool isFullScreen, void(*draw)(SDL_Renderer*,float));
};

#endif