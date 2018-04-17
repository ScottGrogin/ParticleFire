#include"Text.h"

void Text::drawText(SDL_Renderer* renderer, const char* string, Vec2 pos, SDL_Color color,TTF_Font *font){

    int w=0,h=0;
    SDL_Rect Message_rect;
    SDL_Texture* Message; 
    SDL_Surface* surfaceMessage;
    surfaceMessage = TTF_RenderText_Solid(font, string, color); 
    Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_QueryTexture(Message,NULL,NULL,&w,&h);
   
    Message_rect.x = pos.x;  //controls the rect's x coordinate 
    Message_rect.y = pos.y; // controls the rect's y coordinte
    Message_rect.w = w; // controls the width of the rect
    Message_rect.h = h; // controls the height of the rect
    
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect); 
}