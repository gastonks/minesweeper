#include "grid.h"
#include "player.h"
#include "game.h"

void gameLoop(Grid grid){
    //system("clear");
    Move move;

    while(1){
        int allRevealed = allGridRevealed(grid);
        int allFlagged = allGridFlagged(grid);
        //printf("allRevealed=%d\nallFlagged=%d\n", allRevealed, allFlagged);
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
            printLoseGrid(grid, move);
            printf("Your bad move was Y=%ld / X=%ld.\n", move.y, move.x);
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
            if(grid.cases[i][j].state == Revealed && grid.cases[i][j].isMine == 0){
                allRevealed = 1;
            }
        }
    }
    return allRevealed;
}

int allGridFlagged(Grid grid){

    int allFlagged = 1;
    
    for (int i = 0; i < grid.dimension.x; i++)
    {
        for (int j = 0; j < grid.dimension.y; j++)
        {
            if(grid.cases[i][j].state == Flagged && grid.cases[i][j].isMine == 1){
                allFlagged = 0;
            }
        }
    }
    return allFlagged;
}

int mineDetonated(Move move, Grid grid){
    int mineDetonated = 0;

    if(grid.cases[move.x][move.y].isMine == 1 && grid.cases[move.x][move.y].state != Flagged && move.flag == 0)
    {
        mineDetonated = 1;
    }

    return mineDetonated;
}

void printLoseGrid(Grid grid, Move badMove){
    printf("X/Y ");
    for (int i = 0; i < grid.dimension.y; i++)
    {
        printf("%d", i);
    }
    printf("\n");
    for (int j = 0; j < grid.dimension.x; j++)
    {
        printf("   %d", j);
        for (int h = 0; h < grid.dimension.y; h++)
        {
            if(grid.cases[j][h].isMine == 1){
                grid.cases[j][h].icon = 'M';
                printf("%c",grid.cases[j][h].icon);
            }else{
                printf("%c",grid.cases[j][h].icon);
            }
        }
        printf("\n");
    }
    
}