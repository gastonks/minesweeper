#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

struct move
{
    long int x;
    long int y;
    int flag;
};

typedef struct move Move;

Move inputPlayer(long int x, long int y);
void playMove(Grid grid, Move move);
void revealOtherBlank(Grid grid, int x, int y);


#endif