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

    SDL_Color coolColor1 = {100,125,150,255};
    SDL_Color coolColor2 = {255,125,150,255};
    SDL_Color coolColor3 = {100,255,150,255};
    SDL_Color coolColor4 = {100,125,255,255};

    Block* block1 = createBlock(NULL, coolColor1, 200, 30);
    block1->sourceRect->x = 20; block1->sourceRect->y = 20;
    Block* block2 = createBlock(block1, coolColor2, 40, 40);
    block2->sourceRect->x = 400; block2->sourceRect->y = 400;
    Block* block3 = createBlock(block1, coolColor3, 200, 30);
    block3->sourceRect->x = 110; block3->sourceRect->y = 90;

    Block* block4 = createBlock(block1, coolColor4, 40, 40);
    block4->sourceRect->x = 500; block4->sourceRect->y = 500;


    while (gameLoop==1) {

        SDL_SetRenderDrawColor(renderer, anotherColor.r, anotherColor.g, anotherColor.b, anotherColor.a);
        SDL_RenderClear(renderer);
        renderSprite(newSprite, renderer);
        renderBlockNode(block1, renderer);
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
    freeBlock(block1);
    freeBlock(block2);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}