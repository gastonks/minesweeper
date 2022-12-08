#ifndef _GRID_H
#define _GRID_H

#include <stdio.h>
#include <stdlib.h>


enum State{
    Revealed,
    Flagged,
    Empty
};

typedef enum State State;

struct Case
{
    int isMine;
    int mineNearby;
    State state;
};

typedef struct Case Case;


void genGrid(long int x, long int y);

#endif