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


    SDL_Color newColor = {135, 206, 250, 255};
    
    
    SDL_Color groundCol = {255, 230, 153, 255};
    Block* ground = createBlock(NULL, groundCol, 800, 100, BLOCK_NORMAL);
    ground->sourceRect->x = 0; ground->sourceRect->y = 500;

    Block* obstacle = createBlock(ground, groundCol, 50, 50, BLOCK_NORMAL);
    obstacle->sourceRect->x = 200; obstacle->sourceRect->y = 100;

    int gameLoop = 1;
    SDL_Event event;
    SDL_Color anotherColor = {102, 204, 102, 255};
    Sprite* newSprite = createSprite(anotherColor);

    while (gameLoop==1) {

        spriteColliding(newSprite, ground);

        SDL_SetRenderDrawColor(renderer, newColor.r, newColor.g, newColor.b, newColor.a);
        SDL_RenderClear(renderer);
        renderSprite(newSprite, renderer);
        renderBlockNode(ground, renderer);
        SDL_RenderPresent(renderer);
        

        if (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                gameLoop = 0;
            }
            if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP){
                spriteMoveUpdate(newSprite, &event);
            }
        }
        SDL_Delay(10);
    }

    freeSprite(newSprite);
    freeBlock(ground);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}