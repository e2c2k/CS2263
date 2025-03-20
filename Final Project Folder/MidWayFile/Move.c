#include "Board.c"
#include <stdio.h>
#include <stdlib.h>

// Moves specified peice to the right and up
int UpRight(Board *board, int sr, int sc, int xCounter, int oCounter){ // sr = start row, sc = start collumn
  if((sc - 1 >= 0) && (sr + 1 < BOARD_SIZE)){
    board[sr][sc] = board[sr -1][sc +1];
    if(board[sr][sc] == 'x'){
      xCounter--;
      return 1;
    }
    if(board[sr][sc] == 'o'){
      oCounter--;
      return 1;
    }
  }
  printf("Invalid move, try a differnt move.");
  return 0;
}
//Moves piece up and left 
int UpLeft(Board *board, int sr, int sc, int xCounter, int oCounter){
  if((sc - 1 >= 0) && (sr - 1 <= 0)){
    board[sr][sc] = board[sr -1][sc -1];
    if(board[sr][sc] == 'x'){
      xCounter--;
      return 1;
    }
    if(board[sr][sc] == 'o'){
      oCounter--;
      return 1;
    }
  }
  printf("Invalid move, try a differnt move.");
  return 0;
}
//Moves piece down and right
int DownRight(Board *board, int sr, int sc, int xCounter, int oCounter){
if((sc + 1 < BOARD_SiZE) && (sr + 1 < BOARD_SIZE)){
    board[sr][sc] = board[sr +1][sc +1];
    if(board[sr][sc] == 'x'){
      xCounter--;
      return 1;
    }
    if(board[sr][sc] == 'o'){
      oCounter--;
      return 1;
    }
  }
  printf("Invalid move, try a differnt move.");
  return 0;
}
//moves down and left
int DownLeft(Board *board, int sr, int sc, int xCounter, int oCounter){
if((sc + 1 < BOARD_SIZE) && (sr - 1 <= 0)){
    board[sr][sc] = board[sr -1][sc +1];
    if(board[sr][sc] == 'x'){
      xCounter--;
      return 1;
    }
    if(board[sr][sc] == 'o'){
      oCounter--;
      return 1;
    }
  }
  printf("Invalid move, try a differnt move.");
  return 0;
}

//FOR CROWNED PIECES!!
int Up(Board *board, int sr, int sc, int xCounter, int oCounter){
if(sc - 1 >= 0){
    board[sr][sc] = board[sr][sc +1];
    if(board[sr][sc] == 'x'){
      xCounter--;
      return 1;
    }
    if(board[sr][sc] == 'o'){
      oCounter--;
      return 1;
    }
  }
  printf("Invalid move, try a differnt move.");
  return 0;
}
//Moves piece up and left 
int Down(Board *board, int sr, int sc, int xCounter, int oCounter){
if(sc + 1 < BOARD_SIZE){
    board[sr][sc] = board[sr][sc +1];
    if(board[sr][sc] == 'x'){
      xCounter--;
      return 1;
    }
    if(board[sr][sc] == 'o'){
      oCounter--;
      return 1;
    }
  }
  printf("Invalid move, try a differnt move.");
  return 0;
}
//Moves piece down and right
int Left(Board *board, int sr, int sc, int xCounter, int oCounter){
if(sr - 1 >= 0){
    board[sr][sc] = board[sr -1][sc];
    if(board[sr][sc] == 'x'){
      xCounter--;
      return 1;
    }
    if(board[sr][sc] == 'o'){
      oCounter--;
      return 1;
    }
  }
  printf("Invalid move, try a differnt move.");
  return 0;
}
//moves down and left
int Right(Board *board, int sr, int sc, int xCounter, int oCounter){
if(sr + 1 < BOARD_SIZE){
    board[sr][sc] = board[sr +1][sc];
    if(board[sr][sc] == 'x'){
      xCounter--;
      return 1;
    }
    if(board[sr][sc] == 'o'){
      oCounter--;
      return 1;
    }
  }
  printf("Invalid move, try a differnt move.");
  return 0;
}
