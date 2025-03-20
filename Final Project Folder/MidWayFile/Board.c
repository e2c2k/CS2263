#include "Board.h"
#include <stdio.h>
#include <stdlib.h>

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
            }
            else{
                board->tiles[i][j] = '\t';  // Empty space
            } 
        }
    }
}

void printBoard(Board *board){
    printf("\n    0     1    2    3    4    5    6    7\n"); // printing second values following format 11 for example.
    char val = 'A';
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c |", val + i); //printing first values following format 11 for example.
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("  %c |", board->tiles[i][j]); // printing the X and O's on the  board
        }
     printf("\n--------------------------------------------\n");
    }
    printf("\n");
}
void freeBoard(Board *board){
    //GAVIN
}
