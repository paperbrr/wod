#pragma once

#include <SDL.h>
#include "../Gridwork/grid.h"


//enum to deal with different types of blocks
typedef enum{

    BLOCK_NORMAL,
    BLOCK_ACTION

}BlockType;


typedef struct Block{

    //body
    SDL_Rect* sourceRect;
    SDL_Color blockColor;

    //offset positions (of center), have to match with top left 
    float xMid;
    float yMid;

    //type and action (with void* arg, just typecast)
    BlockType blockType;
    void (*actionFunc) (void*);

    //links to other blocks
    struct Block* previousNode;
    struct Block* nextNode;

}Block;

Block* createBlock(Block* head, SDL_Color blockColor, int width, int height, int x, int y, BlockType type, Grid* grid);
void freeBlock(Block* block);
void renderBlockNode(Block* head, SDL_Renderer* renderer);