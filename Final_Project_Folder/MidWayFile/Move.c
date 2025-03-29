 #include "Board.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//sr to move row down is + 1, move up is -1
//sc to move column right is +1, move left is -1
bool jump(char **board, int sr, int sc, int *xCounter, int *oCounter, char player, int movement) { //movement: 1; upRight. 2; downRight. 3; upLeft. 4; downLeft
    // Define opponent's piece
    char opponent_piece1 = (player == 'x') ? 'o' : 'x'; // Opponent’s normal piece
    char opponent_piece2 = (player == 'x') ? 'O' : 'X'; // Opponent’s king piece

    // Check if there is an opponent's piece at (sr, sc)
    if (board[sr][sc] == opponent_piece1 || board[sr][sc] == opponent_piece2) {
        // Find the landing spot
        int new_r;
        int new_c;
        switch(movement){
            case 1:
                new_r = sr-1;
                new_c = sc+1;
                break;
            case 2:
                new_r = sr+1;
                new_c = sc+1;
                break;
            case 3:
                new_r = sr-1;
                new_c = sc-1;
                break;
            case 4:
                new_r = sr+1;
                new_c = sc-1;
                break;
            default:
                printf("invalid move type\n");
                break;
        }
        // Ensure the landing spot is within the board and is empty
        if (new_r >= 0 && new_r < BOARD_SIZE && new_c >= 0 && new_c < BOARD_SIZE &&
            board[new_r][new_r] == ' ') {
            printf("Jump reached\n");
            return true; // Valid jump
        }
    }
    return false; // No valid jump
}

// Moves specified peice to the right and up
bool UpRight(char **board, int sr, int sc, int *xCounter, int *oCounter, char player){ // sr = start row, sc = start collumn
  if ((sr - 1 >= 0) && (sc + 1 < BOARD_SIZE)) {
        int next_r = sr - 1; // Move row up
        int next_c = sc + 1; // Move left
        printf("Movement P1\n");
        if (jump(board, next_r, next_c, xCounter, oCounter, player, 1) == true) {
            int landing_r = next_r - 1; // Landing position
            int landing_c = next_c + 1;
            printf("Movement P2\n");
            if (landing_r >= 0 && landing_c >= 0 && board[landing_r][landing_c] == ' ') {
            	if(board[sr][sc] == player){
            		if(landing_r == 0){
            			board[landing_r][landing_c] = 'X'; // Move player to new position
				board[next_r][next_c] = ' ';  // Remove jumped-over piece
				board[sr][sc] = ' '; 
			}
            		 else if(landing_r == 7){
            			board[landing_r][landing_c] = 'O'; // Move player to new position
				board[next_r][next_c] = ' ';  // Remove jumped-over piece
				board[sr][sc] = ' '; 
			}
			else{
		        	board[landing_r][landing_c] = player; // Move player to new position
				board[next_r][next_c] = ' ';  // Remove jumped-over piece
				board[sr][sc] = ' ';         // Clear original position
			}
		}
		else{
			printf("Movement Crown\n");
			char crown = player - 32;
			board[landing_r][landing_c] = crown; // Move player to new position
			board[next_r][next_c] = ' ';  // Remove jumped-over piece
			board[sr][sc] = ' ';
		}
                // Decrease opponent's counter
                if (player == 'o') (*xCounter)--;
                else (*oCounter)--;
                printf("Movement done\n");
                return true; // Successfully jumped
            }
        }
      else if(board[next_r][next_c] == ' '){
          if(board[sr][sc] == player){
          	if(next_r == 0){
          		board[next_r][next_c] = 'X';  // Remove jumped-over piece
			board[sr][sc] = ' '; 
		}
          	 else if(next_r == 7){
				board[next_r][next_c] = 'O';  // Remove jumped-over piece
				board[sr][sc] = ' '; 
		}
		else{
		        board[next_r][next_c] = player;  // place non crowned piece
		        board[sr][sc] = ' ';         // Clear original position
		}
	}
	else{
	char crown = player - 32;
		board[next_r][next_c] = crown;  // place crowned piece
		board[sr][sc] = ' ';	// Clear original position
	}
        return true;
     }
    }
    printf("invalid move\n");
    Board *temp = createBoard();
    temp ->tiles = board;
    printBoard(temp);
    freeBoard(temp);
    return false; // No valid move
}
//Moves piece up and left 
bool UpLeft(char **board, int sr, int sc, int *xCounter, int *oCounter, char player){
    if ((sr - 1 >= 0) && (sc - 1 >= 0)) {
        int next_r = sr - 1; // Move row up
        int next_c = sc - 1; // Move left
        printf("Movement P1\n");
        if (jump(board, next_r, next_c, xCounter, oCounter, player, 3) == true) {
            int landing_r = next_r - 1; // Landing position
            int landing_c = next_c - 1;
            printf("Movement P2\n");
            if (landing_r >= 0 && landing_c >= 0 && board[landing_r][landing_c] == ' ') {
                if(board[sr][sc] == player){
            		if(landing_r == 0){
            			board[landing_r][landing_c] = 'X'; // Move player to new position
				board[next_r][next_c] = ' ';  // Remove jumped-over piece
				board[sr][sc] = ' '; 
			}
            		 else if(landing_r == 7){
            			board[landing_r][landing_c] = 'O'; // Move player to new position
				board[next_r][next_c] = ' ';  // Remove jumped-over piece
				board[sr][sc] = ' '; 
			}
			else{
		        	board[landing_r][landing_c] = player; // Move player to new position
				board[next_r][next_c] = ' ';  // Remove jumped-over piece
				board[sr][sc] = ' ';         // Clear original position
			}
		}
		else{
			char crown = player - 32;
			board[landing_r][landing_c] = crown; // Move player to new position
			board[next_r][next_c] = ' ';  // Remove jumped-over piece
			board[sr][sc] = ' ';
		}
                // Decrease opponent's counter
                if (player == 'o') (*xCounter)--;
                else (*oCounter)--;
                printf("Movement done\n");
                return true; // Successfully jumped
            }
        }
        else if(board[next_r][next_c]  == ' '){
        if(board[sr][sc] == player){
          	if(next_r == 0){
          		board[next_r][next_c] = 'X';  // Remove jumped-over piece
			board[sr][sc] = ' '; 
		}
          	 else if(next_r == 7){
				board[next_r][next_c] = 'O';  // Remove jumped-over piece
				board[sr][sc] = ' '; 
		}
		else{
		        board[next_r][next_c] = player;  // place non crowned piece
		        board[sr][sc] = ' ';         // Clear original position
		}
	}
	else{
	char crown = player - 32;
		board[next_r][next_c] = crown;  // place crowned piece
		board[sr][sc] = ' ';	// Clear original position
	}
          return true;
      }
    }
    printf("invalid move\n");
    Board *temp = createBoard();
    temp ->tiles = board;
    printBoard(temp);
    freeBoard(temp);
    return false; // No valid move
}
//Moves piece down and right
bool DownRight(char **board, int sr, int sc, int *xCounter, int *oCounter, char player){

 if ((sr + 1 < BOARD_SIZE) && (sc + 1 < BOARD_SIZE)) {
        int next_r = sr + 1; // Move row down
        int next_c = sc + 1; // Move right
        printf("Movement P1\n");
        if (jump(board, next_r, next_c, xCounter, oCounter, player, 2) == true) {
            int landing_r = next_r + 1; // Landing position
            int landing_c = next_c + 1;
            printf("Movement P2\n");
            if (landing_r >= 0 && landing_c >= 0 && board[landing_r][landing_c] == ' ') {
                if(board[sr][sc] == player){
            		if(landing_r == 0){
            			board[landing_r][landing_c] = 'X'; // Move player to new position
				board[next_r][next_c] = ' ';  // Remove jumped-over piece
				board[sr][sc] = ' '; 
			}
            		 else if(landing_r == 7){
            			board[landing_r][landing_c] = 'O'; // Move player to new position
				board[next_r][next_c] = ' ';  // Remove jumped-over piece
				board[sr][sc] = ' '; 
			}
			else{
		        	board[landing_r][landing_c] = player; // Move player to new position
				board[next_r][next_c] = ' ';  // Remove jumped-over piece
				board[sr][sc] = ' ';         // Clear original position
			}
		}
		else{
			char crown = player - 32;
			board[landing_r][landing_c] = crown; // Move player to new position
			board[next_r][next_c] = ' ';  // Remove jumped-over piece
			board[sr][sc] = ' ';
		}

                // Decrease opponent's counter
                if (player == 'o') (*xCounter)--;
                else (*oCounter)--;
                printf("Movement done\n");
                return true; // Successfully jumped
            }
        }
     else if(board[next_r][next_c]  == ' '){
          if(board[sr][sc] == player){
          	if(next_r == 0){
          		board[next_r][next_c] = 'X';  // Remove jumped-over piece
			board[sr][sc] = ' '; 
		}
          	 else if(next_r == 7){
				board[next_r][next_c] = 'O';  // Remove jumped-over piece
				board[sr][sc] = ' '; 
		}
		else{
		        board[next_r][next_c] = player;  // place non crowned piece
		        board[sr][sc] = ' ';         // Clear original position
		}
	}
	else{
	char crown = player - 32;
		board[next_r][next_c] = crown;  // place crowned piece
		board[sr][sc] = ' ';	// Clear original position
	}
          return true;
      }
    }
    printf("invalid move\n");
    Board *temp = createBoard();
    temp ->tiles = board;
    printBoard(temp);
    freeBoard(temp);
    return false; // No valid move
}

//moves down and left
bool DownLeft(char **board, int sr, int sc, int *xCounter, int *oCounter, char player) {
    // Move diagonally down-left if within bounds
    if ((sr + 1 < BOARD_SIZE) && (sc - 1 >= 0)) {
        int next_r = sr + 1; // Move row down
        int next_c = sc - 1; // Move left
        printf("Movement P1\n");
        if (jump(board, next_r, next_c, xCounter, oCounter, player, 4)  == true) {
            int landing_r = next_r + 1; // Landing position
            int landing_c = next_c - 1;
            printf("Movement P2\n");
            if (landing_r >= 0 && landing_c >= 0 && board[landing_r][landing_c] == ' ') {
                if(board[sr][sc] == player){
            		if(landing_r == 0){
            			board[landing_r][landing_c] = 'X'; // Move player to new position
				board[next_r][next_c] = ' ';  // Remove jumped-over piece
				board[sr][sc] = ' '; 
			}
            		 else if(landing_r == 7){
            			board[landing_r][landing_c] = 'O'; // Move player to new position
				board[next_r][next_c] = ' ';  // Remove jumped-over piece
				board[sr][sc] = ' '; 
			}
			else{
		        	board[landing_r][landing_c] = player; // Move player to new position
				board[next_r][next_c] = ' ';  // Remove jumped-over piece
				board[sr][sc] = ' ';         // Clear original position
			}
		}
		else{
			char crown = player - 32;
			board[landing_r][landing_c] = crown; // Move player to new position
			board[next_r][next_c] = ' ';  // Remove jumped-over piece
			board[sr][sc] = ' ';
		}

                // Decrease opponent's counter
                if (player == 'o') (*xCounter)--;
                else (*oCounter)--;
                printf("Movement done\n");
                return true; // Successfully jumped
            }
        }
        else if(board[next_r][next_c]  == ' '){
          if(board[sr][sc] == player){
          	if(next_r == 0){
          		board[next_r][next_c] = 'X';  // Remove jumped-over piece
			board[sr][sc] = ' '; 
		}
          	 else if(next_r == 7){
				board[next_r][next_c] = 'O';  // Remove jumped-over piece
				board[sr][sc] = ' '; 
		}
		else{
		        board[next_r][next_c] = player;  // place non crowned piece
		        board[sr][sc] = ' ';         // Clear original position
		}
	}
	else{
	char crown = player - 32;
		board[next_r][next_c] = crown;  // place crowned piece
		board[sr][sc] = ' ';	// Clear original position
	}
          return true;
      }
    }
    printf("invalid move\n");
    Board *temp = createBoard();
    temp ->tiles = board;
    printBoard(temp);
    freeBoard(temp);
    return false; // No valid move
}
