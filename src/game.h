#ifndef _GAME_H
#define _GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gameLoop(Grid grid);
int allGridRevealed(Grid grid);
int allGridFlagged(Grid grid);
int mineDetonated(Move move, Grid grid);

#endif