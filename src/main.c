#include <SDL.h>
#include <stdio.h>

#include "framework/UIElements/UI.h"
#include "framework/Sprite/sprite.h"

#include "workspace.h"

void actionFunc(){
    printf("something");
}

int main(int argc, char* argv[]) {

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("BOOTLEG PAINT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    SDL_Color newColor = {100,150,200,255};
    Sprite* newSprite = createSprite(newColor);

    int gameLoop = 1;
    SDL_Event event;
    SDL_Color anotherColor = {50,100,150,255};

    while (gameLoop==1) {

        SDL_SetRenderDrawColor(renderer, anotherColor.r, anotherColor.g, anotherColor.b, anotherColor.a);
        SDL_RenderClear(renderer);
        renderSprite(newSprite, renderer);
        SDL_RenderPresent(renderer);

        if (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                gameLoop = 0;
            }
            if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP){
                spriteMoveUpdate(newSprite, &event);
            }
        }
        //SDL_Delay(50);
    }

    freeSprite(newSprite);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}