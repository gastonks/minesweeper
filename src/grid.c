#include "grid.h"

void genGrid(long int x, long int y){
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

    for (int m = 0; m < x; m++)
    {
        free(grid[m]);
    }
    
    free(grid);
}