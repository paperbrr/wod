#include "block.h"
#include <stdio.h>
#include <stdlib.h>


Block* createBlock(Block* head, SDL_Color blockColor, int width, int height, int x, int y, BlockType type, Grid* grid){

    //create block and source rect
    Block* block = malloc(sizeof(Block));
    block->sourceRect = malloc(sizeof(SDL_Rect));
    if (block==NULL || block->sourceRect==NULL) {printf("error"); return NULL;}

    //init 
    block->sourceRect->h = height; block->sourceRect->w = width;
    block->sourceRect->x = x; block->sourceRect->y = y;
    block->blockColor = blockColor;
    block->actionFunc = NULL;
    block->blockType = type;

    //fill cells in area
    cellChangeInArea(grid, x, y, width, height, FILL);

    //node init
    //check if node is first node
    block->nextNode = NULL;
    if (head==NULL){
        block->previousNode = NULL;
        return block;
    }

    //traverse to end; append
    Block* currentNode = head;
    while (currentNode){
        if (currentNode->nextNode == NULL){
            break;
        }
        currentNode = currentNode->nextNode;
    }
    currentNode->nextNode = block;
    block->previousNode = currentNode;

    return block;

}


void freeBlock(Block* block){

    //changes previous and next nodes to new vals
    Block* previous = block->previousNode;
    Block* next = block->nextNode;
    if (block->previousNode){previous->nextNode = next;}
    if (block->nextNode) {next->previousNode = previous;}

    //frees current block
    block->previousNode = block->nextNode = NULL;
    free(block->sourceRect);
    free(block);

}


void renderBlockNode(Block* head, SDL_Renderer* renderer){

    //traverse through nodes
    Block* currentNode = head;
    while (currentNode){
        
        //render prep
        Block* currentBlock = currentNode;
        SDL_Color currentColor = currentBlock->blockColor;
        SDL_SetRenderDrawColor(renderer, currentColor.r, currentColor.g, currentColor.b, currentColor.a);
        SDL_RenderFillRect(renderer, currentBlock->sourceRect);
        
        currentNode = currentNode->nextNode;
    }

}