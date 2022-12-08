#include "player.h"

Move inputPlayer(long int x, long int y){

    Move move;
    int n = 0;

    printf("Enter the Y axis:");
	int error = scanf("%d", &n);

	while (error == 0 || n > y-1)
	{
		fprintf(stderr, "ERROR: Error in the input.\nThe input is not a number or is too high for the grid.\n");
		printf("Try again with a number:");
		getchar();
		error = scanf("%d", &n);
	}
    move.y = n;

    printf("Enter the X axis:");
	error = scanf("%d", &n);
	while (error == 0 || n > x-1)
	{
		fprintf(stderr, "ERROR: Error in the input.\nThe input is not a number or is too high for the grid.\n");
		printf("Try again with a number:");
		getchar();
		error = scanf("%d", &n);
	}
    move.x = n;

    printf("Is it a flag or not ? (0: no, 1: yes) :");
	error = scanf("%d", &n);
	while (error == 0 || n > 2)
	{
		fprintf(stderr, "ERROR: Error in the input.\nThe input is not a number or it's neither 1 nor 2.\n");
		printf("Try again with a number:");
		getchar();
		error = scanf("%d", &n);
	}
    move.flag = n;

    return move;
}

void playMove(Grid grid, Move move){

    int x = move.x;
    int y = move.y;

    if(move.flag == 1){
        //placeFlag(x, y);
    }
    
    if(grid.cases[x][y].isMine == 0){
        grid.cases[x][y].state = Revealed;
        switch (grid.cases[x][y].mineNearby)
        {
        case 0:
            //revealOtherBlank(grid, x, y);
            break;
        default:
            grid.cases[x][y].icon = (char)(grid.cases[x][y].mineNearby+48);
            break;
        }
    }

    if(grid.cases[x][y].isMine == 1){
        grid.cases[x][y].icon = '@';
        grid.cases[x][y].state = Revealed;
    }
}

void revealOtherBlank(Grid grid, int x, int y){

}