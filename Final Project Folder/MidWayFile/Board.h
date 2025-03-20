#ifndef BOARD_H
#define BOARD_H
#define BOARD_SIZE 8
typedef struct{
  char **tiles; //2D array
  int **trackBoard;
}Board;
Board *createBoard(); //to create and allocate space for array
void printBoard(Board *board); // prints a visual board including barriers and all X and O positions
void initializeBoard(Board *board); // creates a base board at the starting positions of checkers.
#endif
