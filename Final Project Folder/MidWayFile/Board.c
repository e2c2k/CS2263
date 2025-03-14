#include "Board.h"
#include <stdio.h>
#include <string.h>

Board * createBoard(){
Board *board = (Board*)malloc(sizeof(Board)); // allocate board
    board->cells = (char**)malloc(SIZE * sizeof(char*)); // allocate array
    for (int i = 0; i < SIZE; i++) {
        board->cells[i] = (char*)malloc(SIZE * sizeof(char)); // allocate each row
    }
    return board;
}

void initializeBoard(Board *board){
  for(int i = 0; i < SIZE; i++){ //row
        for(int j = 0; j < SIZE; j++){ //col
            if((i + j) % 2 == 1){ //for each odd space
                if(i < 3){ // defining which side of the board (O on the top 3 rows)
                    board->cells[i][j] = 'O'; // Player O
                }
                else if(i > 4){ //defining which side of the board(X on the bottom 3 rows)
                    board->cells[i][j] = 'X';  // Player X
                }
            }
            else{
                board->cells[i][j] = ' ';  // Empty space
            } 
            else{
                board->cells[i][j] = ' ';  // Empty space
            }
        }
    }
}

void printBoard(Board *board){
    printf("\n  0 1 2 3 4 5 6 7\n"); // printing second values following format A1 for example.
    char val = 'A';
    for (int i = 0; i < SIZE; i++) {
        printf("%c ", val + i); //printing first values following format A1 for example.
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board->cells[i][j]); // printing the X and O's on the  board
        }
     printf("\n");
    }
    printf("\n");
}
