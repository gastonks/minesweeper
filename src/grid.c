#include "grid.h"

void genGrid(long int x, long int y){
    int** grid = NULL;

    grid = (int**)malloc(x*sizeof(int*));

    for (int i = 0; i < x; i++)
    {
        grid[i] = (int*)malloc(y*sizeof(int));
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            grid[i][j] = 0;
        }
    }
    

    for (int h = 0; h < x; h++)
    {
        for (int l = 0; l < y; l++)
        {
            printf("%d ", grid[h][l]);
        }
        printf("\n");
    }

    for (int m = 0; m < x; m++)
    {
        free(grid[m]);
    }
    
    free(grid);
}