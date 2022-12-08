#ifndef _GRID_H
#define _GRID_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
    char icon;
};

typedef struct Case Case;


void genGrid(long int x, long int y, long int nMine);
void placeMine(Case** grid, long int x, long int y, long int nMine);
void freeGrid(Case** grid, long int x);

#endif