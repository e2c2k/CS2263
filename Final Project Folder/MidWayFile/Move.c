#include "Board.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Moves specified peice to the right and up
bool UpRight(Board *board, int sr, int sc, int *xCounter, int *oCounter){ // sr = start row, sc = start collumn
  if((sc - 1 >= 0) && (sr + 1 < BOARD_SIZE)){
    board->tiles[sr][sc] = board->tiles[sr -1][sc +1];
    if(board->tiles[sr][sc] == 'x' || board->tiles[sr][sc] == 'X'){
      xCounter--;
      return false;
    }
    if(board->tiles[sr][sc] == 'o' || board->tiles[sr][sc] == 'O'){
      oCounter--;
      return false;
    }
  }
  printf("Invalid move, try a differnt move.");
  return true;
}
//Moves piece up and left 
bool UpLeft(Board *board, int sr, int sc, int *xCounter, int *oCounter){
  if((sc - 1 >= 0) && (sr - 1 <= 0)){
    board->tiles[sr][sc] = board->tiles[sr -1][sc -1];
    if(board->tiles[sr][sc] == 'x' || board->tiles[sr][sc] == 'X'){
      xCounter--;
      return false;
    }
    if(board->tiles[sr][sc] == 'o' || board->tiles[sr][sc] == 'O'){
      oCounter--;
      return false;
    }
  }
  printf("Invalid move, try a differnt move.");
  return true;
}
//Moves piece down and right
bool DownRight(Board *board, int sr, int sc, int *xCounter, int *oCounter){
if((sc + 1 < BOARD_SIZE) && (sr + 1 < BOARD_SIZE)){
    board->tiles[sr][sc] = board->tiles[sr +1][sc +1];
    if(board->tiles[sr][sc] == 'x' || board->tiles[sr][sc] == 'X'){
      xCounter--;
      return false;
    }
    if(board->tiles[sr][sc] == 'o' || board->tiles[sr][sc] == 'O'){
      oCounter--;
      return false;
    }
  }
  printf("Invalid move, try a differnt move.");
  return true;
}
//moves down and left
bool DownLeft(Board *board, int sr, int sc, int *xCounter, int *oCounter, char player, char *piece){

    if((sc + 1 < BOARD_SIZE) && (sr - 1 <= 0)){
        board->tiles[sr][sc] = board->tiles[sr -1][sc +1];
        if(jump(board, sr, sc, xCounter, oCounter, player, piece) = true){
            board->tiles[sr][sc] = board->tiles[sr -1][sc +1];
            if(jump(board, sr, sc, xCounter, oCounter, player, piece) = true){
                xCounter--;
                return false;
            }
        }
        else{
        
        }
    }
}

bool jump (Board *board, int sr, int sc, int *xCounter, int *oCounter, char player, char *piece){
    if((board->tiles[sr][sc] == 'x' || board->tiles[sr][sc] == 'X') && (piece != player )){
        return true;
    }
    if(board->tiles[sr][sc] == 'o' || board->tiles[sr][sc] == 'O'){
        return true;
    }
    return false; 
}
