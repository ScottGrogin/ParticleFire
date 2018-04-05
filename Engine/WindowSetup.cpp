#include "WindowSetup.h"
#include<SDL.h>
#include<iostream>


WindowSetup::WindowSetup(int width, int height, int fps, bool isFullScreen, void(*draw)(SDL_Renderer*,float)){
    bool running=true;
   

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event e;

    if(SDL_Init(SDL_INIT_EVERYTHING)<0) {
        std::cout<<"SDL couldn't initialize, ERROR: "<< SDL_GetError()<<std::endl;
        std::cin.get();
    } else {
        //Create window
        if(isFullScreen){
             window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FULLSCREEN );
        } else{
            window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
        }

        renderer =  SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if( window == NULL ) {
            std::cout<<"Window could not be created, ERROR: "<< SDL_GetError()<<std::endl;
            std::cin.get();
        }else if(renderer == NULL) {
            SDL_DestroyWindow(window);
	        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            std::cin.get();
        }else {
            while(running) {

                  while(SDL_PollEvent( &e ) != 0 ){
                    //User requests quit
                    if( e.type == SDL_QUIT ) {
                        running = false;
                    }
                    if(e.type == SDL_KEYDOWN){
                        if(e.key.keysym.sym == SDLK_ESCAPE){
                            running =false;
                        }

                    }
                }

                draw(renderer, 0.0f);
          
            }
        }
    }
    
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    SDL_Quit();

}