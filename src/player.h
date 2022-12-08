/**
* Minesweeper
* @file player.h
* @author Romain Barre
* @date 2022-10-25
* @version 0.1 Debut
* @brief The game 'Minesweeper' in the terminal.
*/

#ifndef _PLAYER_H
#define _PLAYER_H

/* Inclusion of the libraries */
#include <stdio.h>
#include <stdlib.h>

/**
 * @struct move
 * Structure to know where and what the player wants to play
 */
struct move
{
    long int x; /*!< The coordinate X of the play */
    long int y; /*!< The coordinate Y of the play */
    int flag; /*!< If the player wants to place a flag or not */
};

/* Definition of a type for easier access of the structure*/
typedef struct move Move;

/* Prototype functions */
Move inputPlayer(long int x, long int y);
Grid revealCase(Grid grid, Move move);
void revealOtherBlank(Grid grid, int x, int y);
Grid placeFlag(Grid grid, int x, int y);
Grid removeFlag(Grid grid, int x, int y);

#endif