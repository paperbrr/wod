#include "sprite.h"

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>


Sprite* createSprite(SDL_Color spriteColor){

    //create sprite body and initialise
    Sprite* sprite = malloc(sizeof(Sprite));
    SDL_Rect* spriteRect = malloc(sizeof(SDL_Rect));

    if (spriteRect==NULL || sprite==NULL) {printf("error");return NULL;}
    spriteRect->w = 30; spriteRect->h = 30;
    spriteRect->x = 200; spriteRect->y = 200;
    sprite->sourceRect = spriteRect;
    sprite->spriteColor = spriteColor;

    sprite->vx = 0;
    sprite->vy = 0;

    return sprite;

}

void renderSprite(Sprite* sprite, SDL_Renderer* renderer){

    //prep for rendering the sprite from the given workspace
    SDL_Color spriteColor = sprite->spriteColor;
    SDL_SetRenderDrawColor(renderer, spriteColor.r, spriteColor.g, spriteColor.b, spriteColor.a);
    SDL_RenderFillRect(renderer, sprite->sourceRect);

}

void freeSprite(Sprite* sprite){

    //free sprite and sprite source rect
    free(sprite->sourceRect);
    free(sprite);

}