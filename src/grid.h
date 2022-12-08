/**
* Minesweeper
* @file grid.h
* @author Romain Barre
* @date 2022-10-25
* @version 0.1 Debut
* @brief The game 'Minesweeper' in the terminal.
*/

#ifndef _GRID_H
#define _GRID_H

/* Inclusion of libraries */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** @enum State
 * Enumeration of the state of a case
*
*/
enum State{
    Revealed,       /*!< The case is revealed */
    NotRevealed,    /*!< The case is not revealed */
    Flagged         /*!< The case is has a flag */
};

/* Definition of a type for easier access of the structure*/
typedef enum State State;

/**
 * @struct Case
 * Structure for each case of the grid
 */
struct Case
{
    int isMine;     /*!< If case contains a mine or not */
    int mineNearby; /*!< Count the mine nearby */
    State state;    /*!< Know the state of the case */
    char icon;      /*!< For representing the case to the player */
};

/* Definition of a type for easier access of the structure*/
typedef struct Case Case;

/**
 * @struct Dimension
 * Structure for easier access to the dimension of the grid
 */
struct Dimension
{
    long int x; /*!< Dimension X of the grid */
    long int y; /*!< Dimension Y of the grid */
};

/* Definition of a type for easier access of the structure*/
typedef struct Dimension Dimension;

/**
 * @struct grid
 * Structure for a better organisation of the game and the grid.
 */
struct grid
{
    Case** cases;           /*!< The double table of cases for the grid */
    Dimension dimension;    /*!< The dimensions of the grid */
    int nMines;             /*!< The number of mine */
    int nFlag;              /*!< The number of flag */
};

/* Definition of a type for easier access of the structure*/
typedef struct grid Grid;

/* Prototype functions */
Grid genGrid(long int x, long int y, long int nMine);
void placeMine(Grid grid, long int x, long int y, long int nMine);
void printGrid(Grid grid, long int x, long int y);
void freeGrid(Grid grid, long int x);

#endif