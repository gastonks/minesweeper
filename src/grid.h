#ifndef _GRID_H
#define _GRID_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


enum State{
    Revealed,
    NotRevealed,
    Flagged
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

struct Dimension
{
    long int x;
    long int y;
};

typedef struct Dimension Dimension;

struct grid
{
    Case** cases;
    Dimension dimension;
};


typedef struct grid Grid;

Grid genGrid(long int x, long int y, long int nMine);
void placeMine(Grid grid, long int x, long int y, long int nMine);
void printGrid(Grid grid, long int x, long int y);
void freeGrid(Grid grid, long int x);

#endif