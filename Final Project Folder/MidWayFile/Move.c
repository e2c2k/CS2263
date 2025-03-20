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
bool DownLeft(Board *board, int sr, int sc, int *xCounter, int *oCounter, char player) {
    // Move diagonally down-left if within bounds
    if ((sr - 1 >= 0) && (sc - 1 >= 0)) {
        int next_r = sr - 1; // Move row up (for 'o')
        int next_c = sc - 1; // Move left

        if (jump(board, next_r, next_c, xCounter, oCounter, player)) {
            int landing_r = next_r - 1; // Landing position
            int landing_c = next_c - 1;

            if (landing_r >= 0 && landing_c >= 0 && board->tiles[landing_r][landing_c] == ' ') {
                board->tiles[landing_r][landing_c] = player; // Move player to new position
                board->tiles[next_r][next_c] = ' ';  // Remove jumped-over piece
                board->tiles[sr][sc] = ' ';         // Clear original position

                // Decrease opponent's counter
                if (player == 'o') (*xCounter)--;
                else (*oCounter)--;

                return true; // Successfully jumped
            }
        }
    }
    return false; // No valid move
}


bool jump(Board *board, int sr, int sc, int *xCounter, int *oCounter, char player) {
    // Define opponent's piece
    char opponent_piece1 = (player == 'x') ? 'o' : 'x'; // Opponent’s normal piece
    char opponent_piece2 = (player == 'x') ? 'O' : 'X'; // Opponent’s king piece

    // Check if there is an opponent's piece at (sr, sc)
    if (board->tiles[sr][sc] == opponent_piece1 || board->tiles[sr][sc] == opponent_piece2) {
        // Find the landing spot
        int new_r = (player == 'o') ? sr - 1 : sr + 1; // 'o' moves up, 'x' moves down
        int new_c = (sc > 0) ? sc - 1 : sc + 1;        // Left or right

        // Ensure the landing spot is within the board and is empty
        if (new_r >= 0 && new_r < BOARD_SIZE && new_c >= 0 && new_c < BOARD_SIZE &&
            board->tiles[new_r][new_c] == ' ') {
            return true; // Valid jump
        }
    }

    return false; // No valid jump
}



/**
 board->tiles[sr][sc] = board->tiles[sr -1][sc +1];
    if(board->tiles[sr][sc] == 'x' || board->tiles[sr][sc] == 'X'){
       jump(Board *board, int sr, int sc, int *xCounter, int *oCounter);
      xCounter--;
      return false;
    }
    if(board->tiles[sr][sc] == 'o' || board->tiles[sr][sc] == 'O'){
      oCounter--;
      return false;
    }
*/
