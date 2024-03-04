#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

#include "framework/UIElements/UI.h"
#include "framework/Sprite/sprite.h"
#include "framework/Block/block.h"


typedef struct{

    //SDL components
    SDL_Renderer* renderer;

    //Sprite
    Sprite* sprite;

    //Grid
    Grid* grid;

    //Blocks :D
    Block* block1;
    Block* block2;

}Workspace;