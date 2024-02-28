#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

Grid* createGrid(int winW, int winH, int cellSize){

    //allocate memory for grid, cellsArr
    int cellCount = (winW*winH)/(cellSize*cellSize);
    Grid* grid = malloc(sizeof(Grid));
    grid->cellArr = malloc(sizeof(Cell*)*cellCount);
    if (grid->cellArr==NULL || grid==NULL){printf("error");return NULL;}

    //grid init
    grid->cellCount = 0;
    grid->winH = winH;
    grid->winW = winW;
    grid->cellSize = cellSize;

    //iterate through ALL spaces,
    for (int y=0; y<winH; y+=cellSize){
        for (int x=0; x<winW; x+=cellSize){
    
            //create and init cell
            Cell* newCell = malloc(sizeof(Cell));
            if (newCell==NULL) {printf("error"); return NULL;}
            newCell->cellX = x; newCell->cellY = y;
            newCell->filled = 0;

            //assign cell to grid
            grid->cellArr[grid->cellCount] = newCell;
            grid->cellCount += 1;
        }
    }

    return grid;

}


Cell* cellFindFromPos(Grid* grid, int x, int y){

    //variables for simplification
    Cell** cellArr = grid->cellArr;
    Cell* requiredCell = NULL;

    //iterate through cells, match x and y vals, return if found
    for (int i=0; i<grid->cellCount; i++){
        requiredCell = cellArr[i];
        if (requiredCell->cellX == x && requiredCell->cellY == y) {
            return requiredCell;
        }
    }

    return NULL;

}


Cell* cellFindNeighbour(Grid* grid, Cell* cell, LookupOption dir){
    
    int cellSize = grid->cellSize;

    //switch through look up options; return appropriate positions and associated cells
    switch (dir){
        case CELL_UP:
            return cellFindFromPos(grid, cell->cellX, cell->cellY-cellSize);
            break;
        case CELL_DOWN:
            return cellFindFromPos(grid, cell->cellX, cell->cellY+cellSize);
            break;
        case CELL_LEFT:
            return cellFindFromPos(grid, cell->cellX-cellSize, cell->cellY);
            break;
        case CELL_RIGHT:
            return cellFindFromPos(grid, cell->cellX+cellSize, cell->cellY);
            break;
    }

    return NULL;

}


void cellChangeInArea(Grid* grid, int x, int y, int w, int h, FillState fillState){

    //changes fill state of the cell in the given area
    for (int i=x; i<x+w; i+=grid->cellSize){
        for (int j=y; j<y+h; j+=grid->cellSize){
            Cell* cell = cellFindFromPos(grid, i, j);
            if (cell){
                cell->filled = fillState;
            }
        }
    }

}