/**
* Minesweeper
* @file player.c
* @author Romain Barre
* @date 2022-10-25
* @version 0.1 Debut
* @brief The game 'Minesweeper' in the terminal.
*/

/* Inclusion of the libraries */
#include "grid.h"
#include "player.h"
#include "game.h"

/** @fn Move inputPlayer(long int x, long int y)
 * 
 * @param x The dimension X of the grid.
 * @param y The dimension Y of the grid.
 * 
 * @return Return a move from the player.
 * 
 * This function allows the player to the game.
*/
Move inputPlayer(long int x, long int y){

    Move move;
    int n = 0;

    printf("Enter the Y axis (which columns):");
	int error = scanf("%d", &n);

	while (error == 0 || n > y-1)
	{
		fprintf(stderr, "ERROR: Error in the input.\nThe input is not a number or is too high for the grid.\n");
		printf("Try again with a number:");
		getchar();
		error = scanf("%d", &n);
	}
    move.y = n;

    printf("Enter the X axis (which lines):");
	error = scanf("%d", &n);
	while (error == 0 || n > x-1)
	{
		fprintf(stderr, "ERROR: Error in the input.\nThe input is not a number or is too high for the grid.\n");
		printf("Try again with a number:");
		getchar();
		error = scanf("%d", &n);
	}
    move.x = n;

    printf("Is it a flag or not ? (0: no, 1: yes, 2: remove flag) :");
	error = scanf("%d", &n);
	while (error == 0 || n > 3)
	{
		fprintf(stderr, "ERROR: Error in the input.\nThe input is not a number or it's neither 0 nor 1.\n");
		printf("Try again with a number:");
		getchar();
		error = scanf("%d", &n);
	}
    move.flag = n;

    return move;
}


/** void revealOtherBlank(Grid grid, int x, int y)
 * 
 * @param grid The grid of the minesweeper.
 * @param x The coordinate X that the player choose to play on.
 * @param y The coordinate Y that the player choose to play on.
 * 
 * @return Return nothing.
 * 
 * This procedure reveals the case around an empty until a mine is encountered.
*/
void revealOtherBlank(Grid grid, int x, int y){
    int i = x;
    int j = y;
    
    grid.cases[i][j].icon = '.';
    grid.cases[i][j].state = Revealed;

    if( i < 0 && j < 0 && i > grid.dimension.x && j > grid.dimension.y )

    while((i > 0 && j > 0) && (i < grid.dimension.x && j < grid.dimension.y) && grid.cases[i][j].state == NotRevealed && grid.cases[i][j].mineNearby >= 0 && grid.cases[i][j].isMine == 0){
        revealOtherBlank(grid, i-1, j-1);
        revealOtherBlank(grid, i-1, j);
        revealOtherBlank(grid, i+1, j-1);
        revealOtherBlank(grid, i, j+1);
        revealOtherBlank(grid, i+1, j+1);
        revealOtherBlank(grid, i+1, j);
        revealOtherBlank(grid, i+1, j-1);
        revealOtherBlank(grid, i, j-1);
    }


    /*
    while(grid.cases[i][j].state == NotRevealed && grid.cases[i][j].mineNearby == 0 && i > 0 && i < grid.dimension.x-1 && j > 0 && j < grid.dimension.y-1){
        if(grid.cases[i-1][j-1].mineNearby == 0 && grid.cases[i-1][j-1].state == NotRevealed){
            grid.cases[i-1][j-1].icon = '.';
            grid.cases[i-1][j-1].state = Revealed;
        }
        if(grid.cases[i-1][j].mineNearby == 0 && grid.cases[i-1][j-1].state == NotRevealed){
            grid.cases[i-1][j].icon = '.';
            grid.cases[i-1][j].state = Revealed;
        }
        if(grid.cases[i+1][j-1].mineNearby == 0 && grid.cases[i-1][j-1].state == NotRevealed){
            grid.cases[i+1][j-1].icon = '.';
            grid.cases[i+1][j-1].state = Revealed;
        }
        if(grid.cases[i][j+1].mineNearby == 0 && grid.cases[i-1][j-1].state == NotRevealed){
            grid.cases[i][j+1].icon = '.';
            grid.cases[i][j+1].state = Revealed;
        }
        if(grid.cases[i+1][j+1].mineNearby == 0 && grid.cases[i-1][j-1].state == NotRevealed){
            grid.cases[i+1][j+1].icon = '.';
            grid.cases[i+1][j+1].state = Revealed;
        }
        if(grid.cases[i+1][j].mineNearby == 0 && grid.cases[i-1][j-1].state == NotRevealed){
            grid.cases[i+1][j].icon = '.';
            grid.cases[i+1][j].state = Revealed;
        }
        if(grid.cases[i+1][j-1].mineNearby == 0 && grid.cases[i-1][j-1].state == NotRevealed){
            grid.cases[i+1][j-1].icon = '.';
            grid.cases[i+1][j-1].state = Revealed;
        }
        if(grid.cases[i][j-1].mineNearby == 0 && grid.cases[i-1][j-1].state == NotRevealed){
            grid.cases[i][j-1].icon = '.';
            grid.cases[i][j-1].state = Revealed;
        }
    }
    */
}


/** Grid placeFlag(Grid grid, int x, int y)
 * 
 * @param grid The grid of the minesweeper.
 * @param x The coordinate X that the player choose to play on.
 * @param y The coordinate Y that the player choose to play on.
 * 
 * @return Return the grid.
 * 
 * This function places a flag where the player has played.
*/
Grid placeFlag(Grid grid, int x, int y){
    grid.cases[x][y].state = Flagged;
    grid.cases[x][y].icon = 'F';
    grid.nFlag = grid.nFlag + 1;
    return grid;
}

/** Grid removeFlag(Grid grid, int x, int y)
 * 
 * @param grid The grid of the minesweeper.
 * @param x The coordinate X that the player choose to play on.
 * @param y The coordinate Y that the player choose to play on.
 * 
 * @return Return the grid.
 * 
 * This function removes a flag where the player has played.
*/
Grid removeFlag(Grid grid, int x, int y){
    grid.cases[x][y].state = NotRevealed;
    grid.cases[x][y].icon = '#';
    grid.nFlag = grid.nFlag - 1;
    return grid;
}

/** Grid revealCase(Grid grid, Move move)
 * 
 * @param grid The grid of the minesweeper.
 * @param move The move of the player..
 * 
 * @return Return the grid.
 * 
 * This function reveals the case where the player hes played.
*/
Grid revealCase(Grid grid, Move move){

    int x = move.x;
    int y = move.y;

    if((move.flag == 1 || move.flag == 2) && grid.nFlag < grid.nMines){
        if(move.flag == 1){
            grid = placeFlag(grid, x, y);
        }

        if(move.flag == 2 && grid.cases[x][y].state == Flagged){
            grid = removeFlag(grid, x, y);
        }
    }else if(move.flag == 2 && grid.nFlag == grid.nMines){
        if(move.flag == 2 && grid.cases[x][y].state == Flagged){
            grid = removeFlag(grid, x, y);
        }
    }else if (grid.nFlag == grid.nMines && move.flag != 0){
        printf("You can't play more flags.\n");
        return grid;
    }
    
    if(grid.cases[x][y].isMine == 0 && move.flag == 0 && grid.cases[x][y].state == NotRevealed){
        grid.cases[x][y].state = Revealed;
        switch (grid.cases[x][y].mineNearby)
        {
        case 0:
            revealOtherBlank(grid, x, y);
            break;
        default:
            grid.cases[x][y].icon = (char)(grid.cases[x][y].mineNearby+48);
            break;
        }
    }else if(move.flag == 0 && grid.cases[x][y].state == Flagged){
        printf("Remove the flag before.\n");
        return grid;
    }

    if(grid.cases[x][y].isMine == 1 && move.flag == 0){
        grid.cases[x][y].icon = '@';
        grid.cases[x][y].state = Revealed;
    }

    return grid;
}

