#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdio.h>
#include <stdlib.h>

struct move
{
    long int x;
    long int y;
    int flag;
};

typedef struct move Move;

Move inputPlayer(long int x, long int y);
Grid revealCase(Grid grid, Move move);
void revealOtherBlank(Grid grid, int x, int y);
Grid placeFlag(Grid grid, int x, int y);
Grid removeFlag(Grid grid, int x, int y);

#endif