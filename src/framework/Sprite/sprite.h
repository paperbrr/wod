#pragma once

#include <SDL.h>
#include "../Block/block.h"

//sprite struct declaration
typedef struct{

    //body
    SDL_Rect* sourceRect;
    SDL_Color spriteColor;

    //movement stuff
    float vx;
    float vy;

}Sprite;


//sprite function declarations
Sprite* createSprite(SDL_Color spriteColor);
void renderSprite(Sprite* sprite, SDL_Renderer* renderer);
void freeSprite(Sprite* sprite);
void spriteMoveUpdate(Sprite* sprite, SDL_Event* event);
int spriteColliding(Sprite* sprite, Block* head);