#include "grid.h"
#include "player.h"
#include "game.h"

/** @fn void gameLoop(Grid grid)
 * 
 * @param grid The grid of the minesweeper.
 * 
 * @return Return nothing.
 * 
 * This procedure loops the entire game.
*/
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
            printLoseGrid(grid, move);
            printf("Your bad move was Y=%ld / X=%ld.\n", move.y, move.x);
            freeGrid(grid, grid.dimension.x);
            break;
        }
        grid = revealCase(grid, move);
    }
}

/** @fn int allGridRevealed(Grid grid)
 * 
 * @param grid The grid of the minesweeper.
 * 
 * @return Return 1 or 0 if the grid is fully revealed.
 * 
 * This function checks the entire grid to see if the case without a mine are revealed.
*/
int allGridRevealed(Grid grid){

    int allRevealed = 0;


    for (int i = 0; i < grid.dimension.x; i++)
    {
        for (int j = 0; j < grid.dimension.y; j++)
        {
            if(grid.cases[i][j].state != Revealed && grid.cases[i][j].isMine == 0){
                allRevealed = 1;
            }
        }
    }
    return allRevealed;
}

/** @fn int allGridFlagged(Grid grid)
 * 
 * @param grid The grid of the minesweeper.
 * 
 * @return Return 1 or 0 if the grid is fully flagged.
 * 
 * This function checks the entire grid to see if the case with a mine are flagged.
*/
int allGridFlagged(Grid grid){

    int allFlagged = 0;

    if(grid.nFlag != grid.nMines){
        allFlagged = 1;
    }
    
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

/** @fn int mineDetonated(Move move, Grid grid)
 * 
 * @param move Move of the player.
 * @param grid The grid of the minesweeper.
 * 
 * @return Return 1 or 0 if mine explode.
 * 
 * This function checks if the move of the player detonate a mine or not.
*/
int mineDetonated(Move move, Grid grid){
    int mineDetonated = 0;

    if(grid.cases[move.x][move.y].isMine == 1 && grid.cases[move.x][move.y].state != Flagged && move.flag == 0)
    {
        mineDetonated = 1;
    }

    return mineDetonated;
}

/** @fn void printLoseGrid(Grid grid, Move badMove)
 * 
 * @param badMove Move of the player.
 * @param grid The grid of the minesweeper.
 * 
 * @return Return nothing.
 * 
 * This procedure prints the grid when the players loses with the last move played.
*/
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