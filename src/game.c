#include "grid.h"
#include "player.h"
#include "game.h"

void gameLoop(Grid grid){
    system("clear");
    Move move;

    while(1){
        int allRevealed = allGridRevealed(grid);
        int allFlagged = allGridFlagged(grid);

        if(allRevealed == 0 || allFlagged == 0){
            system("clear");
            printf("\nCongratulation, YOU WIN!\n");
            printGrid(grid, grid.dimension.x, grid.dimension.y);
            freeGrid(grid, grid.dimension.x);
            break;
        }

        printGrid(grid, grid.dimension.x, grid.dimension.y);
        move = inputPlayer(grid.dimension.x, grid.dimension.y);
        int detonated = mineDetonated(move, grid);

        if(detonated == 1){
            system("clear");
            printf("\nBOOM, YOU LOSE!\n");
            grid = revealCase(grid, move);
            printGrid(grid, grid.dimension.x, grid.dimension.y);
            freeGrid(grid, grid.dimension.x);
            break;
        }
        grid = revealCase(grid, move);
    }
}

int allGridRevealed(Grid grid){

    int allRevealed = 0;

    if(grid.nFlag != grid.nMines){
        allRevealed = 1;
    }
    for (int i = 0; i < grid.dimension.x; i++)
    {
        for (int j = 0; j < grid.dimension.y; j++)
        {
            if(grid.cases[i][j].state == NotRevealed && grid.cases[i][j].isMine == 0){
                allRevealed = 1;
            }
        }
    }
    return allRevealed;
}

int allGridFlagged(Grid grid){

    int allFlagged = 0;
    for (int i = 0; i < grid.dimension.x; i++)
    {
        for (int j = 0; j < grid.dimension.y; j++)
        {
            if(grid.cases[i][j].state != Flagged && grid.cases[i][j].isMine == 1){
                allFlagged = 1;
            }
        }
    }
    return allFlagged;
}

int mineDetonated(Move move, Grid grid){
    int mineDetonated = 0;

    if(grid.cases[move.x][move.y].isMine == 1 && grid.cases[move.x][move.y].state != Flagged)
    {
        mineDetonated = 1;
    }

    return mineDetonated;
}