#include <stdio.h>
#include "grid.h"
#include "player.h"
#include "game.h"

int main (int argc, char** argv){
    
    system("clear");

    if(argc == 2){
        long int x = strtol(argv[1], NULL, 10);
        int n = 0;
        int maxMine = (int)(x*x);
        printf("Maximum of mines = %d\n", maxMine);

        printf("How many mines do you want:");
		int error = scanf("%d", &n);
		while (error == 0 || n > maxMine)
		{
			fprintf(stderr, "ERROR: Error in the input.\nThe input is not a number or is too high for the grid.\n");

			printf("Try again with a number:");
			getchar();
			error = scanf("%d", &n);
		}

        Grid board;

        board = genGrid(x, x, n);
        board.dimension.x = x;
        board.dimension.y = x;
        board.nMines = n;
        board.nFlag = 0;

        gameLoop(board);

    }else if(argc == 3){

        long int x = strtol(argv[1], NULL, 10);
        long int y = strtol(argv[2], NULL, 10);

        int n = 0;
        int maxMine = (int)(x*y);

        printf("Maximum of mines = %d\n", maxMine);
        printf("How many mines do you want:");
		int error = scanf("%d", &n);
		while (error == 0 || n > maxMine)
		{
			fprintf(stderr, "ERROR: Error in the input.\n The input is not a number or is too high for the grid.\n");

			printf("Try again with a number:");
			getchar();
			error = scanf("%d", &n);
		}

        Grid board;

        board = genGrid(x, x, n);
        board.dimension.x = x;
        board.dimension.y = y;
        board.nMines = n;
        board.nFlag = 0;

        gameLoop(board);
    }

    return 0;
}