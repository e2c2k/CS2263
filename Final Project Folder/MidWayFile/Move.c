#include "Board.c"
#include <stdio.h>
#include <stdlib.h>

// Moves specified peice to the right and up
boolean UpRight(Board *board, int sr, int sc, int *xCounter, int *oCounter){ // sr = start row, sc = start collumn
  if((sc - 1 >= 0) && (sr + 1 < BOARD_SIZE)){
    board[sr][sc] = board[sr -1][sc +1];
    if(board[sr][sc] == 'x' || board[sr][sc] == 'X'){
      xCounter--;
      return true;
    }
    if(board[sr][sc] == 'o' || board[sr][sc] == 'O'){
      oCounter--;
      return true;
    }
  }
  printf("Invalid move, try a differnt move.");
  return false;
}
//Moves piece up and left 
boolean UpLeft(Board *board, int sr, int sc, int *xCounter, int *oCounter){
  if((sc - 1 >= 0) && (sr - 1 <= 0)){
    board[sr][sc] = board[sr -1][sc -1];
    if(board[sr][sc] == 'x' || board[sr][sc] == 'X'){
      xCounter--;
      return true;
    }
    if(board[sr][sc] == 'o' || board[sr][sc] == 'O'){
      oCounter--;
      return true;
    }
  }
  printf("Invalid move, try a differnt move.");
  return false;
}
//Moves piece down and right
boolean DownRight(Board *board, int sr, int sc, int *xCounter, int *oCounter){
if((sc + 1 < BOARD_SiZE) && (sr + 1 < BOARD_SIZE)){
    board[sr][sc] = board[sr +1][sc +1];
    if(board[sr][sc] == 'x' || board[sr][sc] == 'X'){
      xCounter--;
      return true;
    }
    if(board[sr][sc] == 'o' || board[sr][sc] == 'O'){
      oCounter--;
      return true;
    }
  }
  printf("Invalid move, try a differnt move.");
  return false;
}
//moves down and left
int DownLeft(Board *board, int sr, int sc, int *xCounter, int *oCounter){
if((sc + 1 < BOARD_SIZE) && (sr - 1 <= 0)){
    board[sr][sc] = board[sr -1][sc +1];
    if(board[sr][sc] == 'x' || board[sr][sc] == 'X'){
      xCounter--;
      return true;
    }
    if(board[sr][sc] == 'o' || board[sr][sc] == 'O'){
      oCounter--;
      return true;
    }
  }
  printf("Invalid move, try a differnt move.");
  return false;
}

//FOR CROWNED PIECES!!
boolean Up(Board *board, int sr, int sc, int *xCounter, int *oCounter){
if(sc - 1 >= 0){
    board[sr][sc] = board[sr][sc +1];
    if(board[sr][sc] == 'x' || board[sr][sc] == 'X'){
      xCounter--;
      return true;
    }
    if(board[sr][sc] == 'o' || board[sr][sc] == 'O'){
      oCounter--;
      return true;
    }
  }
  printf("Invalid move, try a differnt move.");
  return false;
}
//Moves piece up and left 
boolean Down(Board *board, int sr, int sc, int *xCounter, int *oCounter){
if(sc + 1 < BOARD_SIZE){
    board[sr][sc] = board[sr][sc +1];
    if(board[sr][sc] == 'x' || board[sr][sc] == 'X'){
      xCounter--;
      return true;
    }
    if(board[sr][sc] == 'o' || board[sr][sc] == 'O'){
      oCounter--;
      return true;
    }
  }
  printf("Invalid move, try a differnt move.");
  return false;
}
//Moves piece down and right
boolean Left(Board *board, int sr, int sc, int *xCounter, int *oCounter){
if(sr - 1 >= 0){
    board[sr][sc] = board[sr -1][sc];
    if(board[sr][sc] == 'x' || board[sr][sc] == 'X'){
      xCounter--;
      return true;
    }
    if(board[sr][sc] == 'o' || board[sr][sc] == 'O'){
      oCounter--;
      return true;
    }
  }
  printf("Invalid move, try a differnt move.");
  return false;
}
//moves down and left
boolean Right(Board *board, int sr, int sc, int *xCounter, int *oCounter){
if(sr + 1 < BOARD_SIZE){
    board[sr][sc] = board[sr +1][sc];
    if(board[sr][sc] == 'x' || board[sr][sc] == 'X'){
      xCounter--;
      return true;
    }
    if(board[sr][sc] == 'o' || board[sr][sc] == 'O'){
      oCounter--;
      return true;
    }
  }
  printf("Invalid move, try a differnt move.");
  return false;
}
