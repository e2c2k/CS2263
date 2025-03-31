#ifndef MOVE_H
#define MOVE_H
#include <stdbool.h>

#include "board.h"  // Ensure Board is known

bool UpRight(char **tiles, int sr, int sc, int *xCounter, int *oCounter, char player);
bool UpLeft(char **tiles, int sr, int sc, int *xCounter, int *oCounter, char player);
bool DownRight(char **tiles, int sr, int sc, int *xCounter, int *oCounter, char player);
bool DownLeft(char **tiles, int sr, int sc, int *xCounter, int *oCounter, char player);

#endif

