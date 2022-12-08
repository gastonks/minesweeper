#include "grid.h"
#include "player.h"
#include "game.h"

void gameLoop(Grid grid){
    Move move;

    while(1){

        int allRevealed = allGridRevealed(grid);
        int allFlagged = allGridFlagged(grid);
        if(allRevealed == 0 || allFlagged == 0){
            printf("\nCongratulation, YOU WIN!\n");
            break;
        }

        printGrid(grid, grid.dimension.x, grid.dimension.y);
        move = inputPlayer(grid.dimension.x, grid.dimension.y);
        revealCase(grid, move);
    }
}

int allGridRevealed(Grid grid){

    int allRevealed = 0;
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