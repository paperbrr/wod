#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

#include "framework/UIElements/UI.h"
#include "framework/Sprite/sprite.h"


typedef struct{

    //SDL components
    SDL_Renderer* renderer;

    //Sprite
    Sprite* sprite;

}Workspace;