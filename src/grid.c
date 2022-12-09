/**
* Minesweeper
* @file grid.c
* @author Romain Barre
* @date 2022-10-25
* @version 0.1 Debut
* @brief The game 'Minesweeper' in the terminal.
*/

/* Inclusion of the libraries */
#include "grid.h"
#include "player.h"

/** @fn Grid genGrid(long int x, long int y, long int nMine)
 * 
 * @param x The dimension X of the grid.
 * @param y The dimension Y of the grid.
 * @param nMine The number of mine the player choose.
 * 
 * @return Return a new grid the game.
 * 
 * This function generates a new grid for a new game of minesweeper.
*/
Grid genGrid(long int x, long int y, long int nMine){
    Grid grid;

    grid.nMines = nMine;
    grid.nFlag = 0;

    grid.cases = NULL;

    grid.cases = (Case**)malloc(x*sizeof(Case*));

    for (int i = 0; i < x; i++)
    {
        grid.cases[i] = (Case*)malloc(y*sizeof(Case));
    }
    for (int j= 0; j < x; j++)
    {
        for (int k = 0; k < y; k++)
        {
            grid.cases[j][k].isMine = 0;
            grid.cases[j][k].mineNearby = 0;
            grid.cases[j][k].state = NotRevealed;
            grid.cases[j][k].icon = '#';
        }
    }
    
    placeMine(grid, x, y, nMine);
/*
    for (int h = 0; h < x; h++)
    {
        for (int l = 0; l < y; l++)
        {
            printf("%d ", grid.cases[h][l].isMine);
        }
        printf("\n");
    }

*/
/*
    printf("\n\n----------------------------------------------------------\n\n");


    for (int h = 0; h < x; h++)
    {
        for (int l = 0; l < y; l++)
        {
            printf("%d ", grid[h][l].mineNearby);
        }
        printf("\n");
    }
*/
    return grid;

}


/** @fn void placeMine(Grid grid, long int x, long int y, long int nMine)
 * 
 * @param grid The grid fo minesweeper.
 * @param x The dimension X of the grid.
 * @param y The dimension Y of the grid.
 * @param nMine The number of mine the player choose.
 * 
 * @return Return nothing.
 * 
 * This procedure places mines randomly in the grid.
*/
void placeMine(Grid grid, long int x, long int y, long int nMine){
    
    srand(time(NULL));

    int n = 0;
    int i = 0;
    int j = 0;

    while (n < nMine)
    {
        i = rand() % x;
        j = rand() % y;

        if(grid.cases[i][j].isMine == 1){
            while(grid.cases[i][j].isMine == 1){
                i = rand() % x;
                j = rand() % y;
            }
            grid.cases[i][j].isMine = 1;
            n++;
        }else{
            grid.cases[i][j].isMine = 1;
            n++;
        }


        //printf("i = %d\nj = %d\n", i, j);

        /* mine in the middle of the grid.cases*/
        if((i > 0 && j > 0) && (i < x-1 && j < y-1)){
            grid.cases[i-1][j-1].mineNearby++;
            grid.cases[i-1][j].mineNearby++;
            grid.cases[i-1][j+1].mineNearby++;
            grid.cases[i][j-1].mineNearby++;
            grid.cases[i][j+1].mineNearby++;
            grid.cases[i+1][j-1].mineNearby++;
            grid.cases[i+1][j].mineNearby++;
            grid.cases[i+1][j+1].mineNearby++;
        }
        /* mine the top left corner */
        else if(i == 0 && j == 0){
            //printf("i == 0 && j == 0\n");
            grid.cases[i][j+1].mineNearby++;
            grid.cases[i+1][j].mineNearby++;
            grid.cases[i+1][j+1].mineNearby++;
        }
        /* mine in the bottom right corner */
        else if(i == x-1 && j == y-1){
            //printf("i == x-1 && j == y-1\n");
            grid.cases[i-1][j].mineNearby++;
            grid.cases[i-1][j-1].mineNearby++;
            grid.cases[i][j-1].mineNearby++;
        }
        /* mine in the bottom left corner */
        else if(i == x-1 && j == 0){
            //printf("i == x-1 && j == 0\n");
            grid.cases[i][j+1].mineNearby++;
            grid.cases[i-1][j].mineNearby++;
            grid.cases[i-1][j+1].mineNearby++;
        }
        /* mine in the top right corner*/
        else if(i == 0 && j == y-1){
            //printf("i == 0 && j == y-1\n");
            grid.cases[i][j-1].mineNearby++;
            grid.cases[i+1][j].mineNearby++;
            grid.cases[i+1][j-1].mineNearby++;
        }
        /* mine on the left side */
        else if(( i > 0 && i < x-1) && j == 0){
            //printf("( i > 0 && i < x-1) && j == 0\n");
            grid.cases[i-1][j].mineNearby++;
            grid.cases[i+1][j].mineNearby++;
            grid.cases[i+1][j+1].mineNearby++;
            grid.cases[i][j+1].mineNearby++;
            grid.cases[i-1][j+1].mineNearby++;
        }
        /* mine on the right side*/
        else if(( i > 0 && i < x-1) && j == y-1){
            //printf("( i > 0 && i < x-1) && j == y-1)\n");
            grid.cases[i-1][j].mineNearby++;
            grid.cases[i+1][j].mineNearby++;
            grid.cases[i+1][j-1].mineNearby++;
            grid.cases[i][j-1].mineNearby++;
            grid.cases[i-1][j-1].mineNearby++;
        }
        /* mine on the bottom side*/
        else if( i == x-1 && (j > 0 && j < y-1)){
            //printf("( i > 0 && i < x-1) && j == y-1)\n");
            grid.cases[i][j+1].mineNearby++;
            grid.cases[i][j-1].mineNearby++;
            grid.cases[i-1][j-1].mineNearby++;
            grid.cases[i-1][j].mineNearby++;
            grid.cases[i-1][j+1].mineNearby++;
        }
        /* mine on the top side*/
        else if( i == 0 && (j > 0 && j < y-1)){
            //printf("( i > 0 && i < x-1) && j == y-1)\n");
            grid.cases[i][j-1].mineNearby++;
            grid.cases[i][j+1].mineNearby++;
            grid.cases[i+1][j-1].mineNearby++;
            grid.cases[i+1][j].mineNearby++;
            grid.cases[i+1][j+1].mineNearby++;
        }
    }
}

/** @fn void printGrid(Grid grid, long int x, long int y)
 * 
 * @param grid The grid fo minesweeper.
 * @param x The dimension X of the grid.
 * @param y The dimension Y of the grid.
 * 
 * @return Return nothing.
 * 
 * This procedure prints the grid with the icons of each case.
*/
void printGrid(Grid grid, long int x, long int y){
    printf("X/Y ");
    for (int i = 0; i < y; i++)
    {
        printf("%d", i);
    }
    printf("\n");
    for (int j = 0; j < x; j++)
    {
        printf("   %d", j);
        for (int h = 0; h < y; h++)
        {
            printf("%c",grid.cases[j][h].icon);
        }
        printf("\n");
    }
    printf("Mines : %d / %d\n", grid.nFlag, grid.nMines);
}

/** @fn void freeGrid(Grid grid, long int x)
 * 
 * @param grid The grid fo minesweeper.
 * @param x The dimension X of the grid.
 * 
 * @return Return nothing.
 * 
 * This procedure frees the memory.
*/
void freeGrid(Grid grid, long int x){
    for (int m = 0; m < x; m++)
    {
        free(grid.cases[m]);
    }
    
    free(grid.cases);
}