#include "grid.h"

void genGrid(long int x, long int y, long int nMine){
    Case** grid = NULL;

    grid = (Case**)malloc(x*sizeof(Case*));

    for (int i = 0; i < x; i++)
    {
        grid[i] = (Case*)malloc(y*sizeof(Case));
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            grid[i][j].isMine = 0;
            grid[i][j].mineNearby = 0;
            grid[i][j].state = Empty;
        }
    }
    

    for (int h = 0; h < x; h++)
    {
        for (int l = 0; l < y; l++)
        {
            printf("%d ", grid[h][l].mineNearby);
        }
        printf("\n");
    }
    printf("\n\n----------------------------------------------------------\n\n");
    placeMine(grid, x, y, nMine);

    for (int h = 0; h < x; h++)
    {
        for (int l = 0; l < y; l++)
        {
            printf("%d ", grid[h][l].isMine);
        }
        printf("\n");
    }

    printf("\n\n----------------------------------------------------------\n\n");


    for (int h = 0; h < x; h++)
    {
        for (int l = 0; l < y; l++)
        {
            printf("%d ", grid[h][l].mineNearby);
        }
        printf("\n");
    }

    freeGrid(grid, x);
}

void placeMine(Case** grid, long int x, long int y, long int nMine){
    
    srand(time(NULL));

    int n = 0;
    int i = 0;
    int j = 0;

    while (n < nMine)
    {
        i = rand() % x;
        j = rand() % y;

        if(grid[i][j].isMine == 1){
            while(grid[i][j].isMine == 1){
                i = rand() % x;
                j = rand() % y;
            }
            grid[i][j].isMine = 1;
            n++;
        }else{
            grid[i][j].isMine = 1;
            n++;
        }


        //printf("i = %d\nj = %d\n", i, j);

        /* mine in the middle of the grid*/
        if((i > 0 && j > 0) && (i < x-1 && j < y-1)){
            grid[i-1][j-1].mineNearby++;
            grid[i-1][j].mineNearby++;
            grid[i-1][j+1].mineNearby++;
            grid[i][j-1].mineNearby++;
            grid[i][j+1].mineNearby++;
            grid[i+1][j-1].mineNearby++;
            grid[i+1][j].mineNearby++;
            grid[i+1][j+1].mineNearby++;
        }
        /* mine the top left corner */
        else if(i == 0 && j == 0){
            //printf("i == 0 && j == 0\n");
            grid[i][j+1].mineNearby++;
            grid[i+1][j].mineNearby++;
            grid[i+1][j+1].mineNearby++;
        }
        /* mine in the bottom right corner */
        else if(i == x-1 && j == y-1){
            //printf("i == x-1 && j == y-1\n");
            grid[i-1][j].mineNearby++;
            grid[i-1][j-1].mineNearby++;
            grid[i][j-1].mineNearby++;
        }
        /* mine in the bottom left corner */
        else if(i == x-1 && j == 0){
            //printf("i == x-1 && j == 0\n");
            grid[i][j+1].mineNearby++;
            grid[i-1][j].mineNearby++;
            grid[i-1][j+1].mineNearby++;
        }
        /* mine in the top right corner*/
        else if(i == 0 && j == y-1){
            //printf("i == 0 && j == y-1\n");
            grid[i][j-1].mineNearby++;
            grid[i+1][j].mineNearby++;
            grid[i+1][j-1].mineNearby++;
        }
        /* mine on the left side */
        else if(( i > 0 && i < x-1) && j == 0){
            //printf("( i > 0 && i < x-1) && j == 0\n");
            grid[i-1][j].mineNearby++;
            grid[i+1][j].mineNearby++;
            grid[i+1][j+1].mineNearby++;
            grid[i][j+1].mineNearby++;
            grid[i-1][j+1].mineNearby++;
        }
        /* mine on the right side*/
        else if(( i > 0 && i < x-1) && j == y-1){
            //printf("( i > 0 && i < x-1) && j == y-1)\n");
            grid[i-1][j].mineNearby++;
            grid[i+1][j].mineNearby++;
            grid[i+1][j-1].mineNearby++;
            grid[i][j-1].mineNearby++;
            grid[i-1][j-1].mineNearby++;
        }
        /* mine on the bottom side*/
        else if( i == x-1 && (j > 0 && j < y-1)){
            //printf("( i > 0 && i < x-1) && j == y-1)\n");
            grid[i][j+1].mineNearby++;
            grid[i][j-1].mineNearby++;
            grid[i-1][j-1].mineNearby++;
            grid[i-1][j].mineNearby++;
            grid[i-1][j+1].mineNearby++;
        }
        /* mine on the top side*/
        else if( i == 0 && (j > 0 && j < y-1)){
            //printf("( i > 0 && i < x-1) && j == y-1)\n");
            grid[i][j-1].mineNearby++;
            grid[i][j+1].mineNearby++;
            grid[i+1][j-1].mineNearby++;
            grid[i+1][j].mineNearby++;
            grid[i+1][j+1].mineNearby++;
        }



    }
    
    
}

void freeGrid(Case** grid, long int x){
    for (int m = 0; m < x; m++)
    {
        free(grid[m]);
    }
    
    free(grid);
}