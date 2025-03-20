#include "Board.h"
#include <stdio.h>
#include <stdlib.h>

#define WHITE_BG  "\x1b[47m"  // White background
#define BLACK_BG  "\x1b[40m"  // Black background
#define RESET     "\x1b[0m"   // Reset colors

// ANSI for checkers pieces
#define RED_PIECE  "\x1b[31mo\x1b[0m"  // Red piece (Player O)
#define BLACK_PIECE "\x1b[37mx\x1b[0m"  // White text on black background (Player X)



Board * createBoard(){
    Board *board;
    board = (Board*)malloc(sizeof(Board)); // allocate board
    board->tiles = (char**)malloc(BOARD_SIZE * sizeof(char*)); // allocate array
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->tiles[i] = (char*)malloc(BOARD_SIZE * sizeof(char)); // allocate each row
    }
    return board;
}

void initializeBoard(Board *board){
  for(int i = 0; i < BOARD_SIZE; i++){ //row
        for(int j = 0; j < BOARD_SIZE; j++){ //col
            if((i + j) % 2 == 1){ //for each odd space
                if(i < 3){ // defining which side of the board (O on the top 3 rows)
                    board->tiles[i][j] = 'o'; // Player O
                }
                else if(i > 4){ //defining which side of the board(X on the bottom 3 rows)
                    board->tiles[i][j] = 'x';  // Player X
                }
                 else{
                    board->tiles[i][j] = ' ';  // Empty space
                } 
            }
            else{
                board->tiles[i][j] = ' ';  // Empty space
            } 
        }
    }
}

void printBoard(Board *board) {
    printf("\n    ");  
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d   ", i); // Column numbers
    }
    printf("\n  ---------------------------------\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i); // Row number
        for (int j = 0; j < BOARD_SIZE; j++) {
            char *bgColor = ((i + j) % 2 == 0) ? WHITE_BG : BLACK_BG; // Alternating squares
            
            // Get piece character with color
            char *piece;
            if (board->tiles[i][j] == 'x') {
                piece = BLACK_PIECE;  // Player X
            } else if (board->tiles[i][j] == 'o') {
                piece = RED_PIECE;  // Player O
            } else {
                piece = " ";  // Empty space
            }

            // Print with background color
            printf("%s %s %s|", bgColor, piece, RESET);
        }
        printf("\n  ---------------------------------\n");
    }
}
void freeBoard(Board *board){
    //GAVIN
}
