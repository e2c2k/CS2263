#include "Board.c"
#include <stdio.h>
#include <stdlib.h>

// Moves specified peice to the right and up
void UpRight(Board *board, int sr, int sc){ // sr = start row, sc = start collumn
  if((sc - 1 >= 0) && (sr + 1 < BOARD_SIZE)){
    board[sr][sc] = board[sr -1][sc +1];
    return;
  }
  printf("Invalid move, try a differnt move.");
  return;
}
//Moves piece up and left 
void UpLeft(Board *board, int sr, int sc){
  if((sc - 1 >= 0) && (sr - 1 <= 0)){
    board[sr][sc] = board[sr -1][sc -1];
    return;
  }
  printf("Invalid move, try a differnt move.");
  return;
}
//Moves piece down and right
void DownRight(Board *board, int sr, int sc){
if((sc + 1 < BOARD_SiZE) && (sr + 1 < BOARD_SIZE)){
    board[sr][sc] = board[sr +1][sc +1];
    return;
  }
  printf("Invalid move, try a differnt move.");
  return;
}
//moves down and left
void DownLeft(Board *board, int sr, int sc){
if((sc + 1 < BOARD_SIZE) && (sr - 1 <= 0)){
    board[sr][sc] = board[sr -1][sc +1];
    return;
  }
  printf("Invalid move, try a differnt move.");
  return;
}

//FOR CROWNED PIECES!!
void Up(Board *board, int sr, int sc){
if(sc - 1 >= 0){
    board[sr][sc] = board[sr][sc +1];
    return;
  }
  printf("Invalid move, try a differnt move.");
  return;
}
//Moves piece up and left 
void Down(Board *board, int sr, int sc){
if(sc + 1 < BOARD_SIZE){
    board[sr][sc] = board[sr][sc +1];
    return;
  }
  printf("Invalid move, try a differnt move.");
  return;
}
//Moves piece down and right
void Left(Board *board, int sr, int sc){
if(sr - 1 >= 0){
    board[sr][sc] = board[sr -1][sc];
    return;
  }
  printf("Invalid move, try a differnt move.");
  return;
}
//moves down and left
void Right(Board *board, int sr, int sc){
if(sr + 1 < BOARD_SIZE){
    board[sr][sc] = board[sr +1][sc];
    return;
  }
  printf("Invalid move, try a differnt move.");
  return;
}
