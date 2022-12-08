/**
* Minesweeper
* @file game.h
* @author Romain Barre
* @date 2022-10-25
* @version 0.1 Debut
* @brief The game 'Minesweeper' in the terminal.
*/

#ifndef _GAME_H
#define _GAME_H

/* Inclusion of libraries */
#include <stdio.h>
#include <stdlib.h>

/* Prototype functions */
void gameLoop(Grid grid);
int allGridRevealed(Grid grid);
int allGridFlagged(Grid grid);
int mineDetonated(Move move, Grid grid);
void printLoseGrid(Grid grid, Move badMove);

#endif