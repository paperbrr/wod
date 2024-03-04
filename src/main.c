#include <SDL.h>
#include <stdio.h>
#include <math.h>

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
    
    window = SDL_CreateWindow("BOOTLEG PAINT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 810, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Grid* grid = createGrid(810, 600, 30);


    SDL_Color newColor = {135, 206, 250, 255};
    
    
    SDL_Color groundCol = {255, 230, 153, 255};
    Block* ground = createBlock(NULL, groundCol, 810, 90, 0, 510, BLOCK_NORMAL, grid);
    //Block* obstacle = createBlock(ground, groundCol, 50, 50, 200, 100, BLOCK_NORMAL, grid);

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
            if (event.type == SDL_MOUSEBUTTONDOWN){
                int xPos = event.motion.x; int yPos = event.motion.y;
                xPos = 30*floor((double) xPos/30);
                yPos = 30*floor((double) yPos/30);
                Cell* yes = cellFindFromPos(grid, xPos, yPos);
                if (yes) {printf("%i\n",yes->filled);}
                else {printf("tomfoolery :D");}
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