
/*
    if(i < 0 || j < 0 || i >= grid.dimension.x || j >= grid.dimension.y){
        printf("\nRETURN\n");
        return;
    }else{
        printf("\nIF\n");
        printf("grid.cases[i][j].isMine=%d\n", grid.cases[i][j].isMine);
        printf("grid.cases[i][j].mineNearby=%d\n", grid.cases[i][j].mineNearby);
        printf("grid.cases[i][j].state=%d\n", grid.cases[i][j].state);
        if(grid.cases[i][j].isMine == 0 && grid.cases[i][j].state == 0){
            if(grid.cases[i][j].mineNearby == 0){
                grid.cases[i][j].icon = '.';
            }else{
                grid.cases[i][j].icon = (char)(grid.cases[i][j].mineNearby+48);
            }
            printf("\n.\n");
            move.flag = 0;


            move.x = i-1;
            move.y = j-1;
            revealCase(grid, move);

            move.x = i-1;
            move.y = j;
            revealCase(grid, move);

            move.x = i+1;
            move.y = j-1;
            revealCase(grid, move);

            move.x = i;
            move.y = j+1;
            revealCase(grid, move);

            move.x = i+1;
            move.y = j+1;
            revealCase(grid, move);

            move.x = i+1;
            move.y = j;
            revealCase(grid, move);

            move.x = i+1;
            move.y = j-1;
            revealCase(grid, move);

            move.x = i;
            move.y = j-1;
            revealCase(grid, move);
        }
    }
*/
/*
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
*/

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