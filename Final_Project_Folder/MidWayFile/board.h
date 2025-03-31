#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 8

typedef struct {
    char **tiles; // 2D array to hold the board's tiles
} Board;

// Function declarations
Board *createBoard();           // Creates and allocates space for the board
void printBoard(Board *board);   // Prints the visual board, 
void initializeBoard(Board *board); // Initializes the board with the starting positions
void freeBoard(Board *board);    // Frees the allocated space for the board

#endif // BOARD_H
