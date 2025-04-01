#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "move.h"
#include "txtFiles.h"
#define BOARD_SIZE 8
int main(){
    int choice;
    printf("Welcome to Checkers!\n");

    while (1) {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Start New Game\n");
        printf("2. Display game sstatistics \n");
        printf("3. Reset game statistics\n");  
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Play the Game
                Board *board = createBoard();
                initializeBoard(board);
                bool playing = true;
                int xCounter = 12;
                int oCounter = 12;
                int sr;
                int sc;
                int pChoice;
                char player = 'x';
                bool valid = false;
                bool isValidMove;
                while(playing){
                    printBoard(board->tiles);
                    printf("Current Score:\nPlayer 1: %d Pieces captured\nPlayer 2: %d Pieces captured\n", 12 - oCounter, 12 - xCounter);
                    if(xCounter == 0){
                        printf(" O's win!\n");
                        UpdateScoreBoard(2);
                        playing = false;
                    }
                    if(oCounter == 0){
                        printf("X's win!\n");
                        UpdateScoreBoard(1);
                        playing = false;
                    }
                    else{
                        
                        while(!valid){
                        	printf("player %c Select your source position:\n", player);
                        	isValidMove = false;
                        	while(!isValidMove){
		                    printf("Select the row of the piece to move: ");
		                    scanf(" %d", &sr);
		                    
		                    printf("Select the column of the piece to move: ");
		                    scanf(" %d", &sc);
		                    if((sr < 8 && sr > 0) || (sc < 8 && sc > 0)){
		                    	isValidMove = true;
		                    }
		                    else{
		                    isValidMove = false;
		                    	printf("invalid position on the board\n");
		                    }
		                }
                            if(board->tiles[sr][sc] == player){
                            	if(player == 'x'){
		                        printf("\nMovement choices:\n");
		                        printf("1. up right\n");
		                        printf("2. up left\n");
		                        printf("3. Exit game\n");                            
		                        printf("Your choice: ");
		                        scanf(" %d", &pChoice);
		                 }
		                 else{
		                 	printf("\nMovement choices:\n");
		                        printf("1. down right\n");
		                        printf("2. down left\n");
		                        printf("3. Exit game\n");                            
		                        printf("Your choice: ");
		                        scanf(" %d", &pChoice);
		                  }
                                switch(pChoice){
                                    case 1:
                                        if(board->tiles[sr][sc] == 'x'){
                                            valid = UpRight(board->tiles, sr, sc, &xCounter, &oCounter, player);
                                        }
                                        else{
                                            valid = DownRight(board->tiles, sr, sc, &xCounter, &oCounter, player);
                                        }    
                                        break;
                                    
                                        case 2:
                                            if(board->tiles[sr][sc] == 'x'){
                                                valid = UpLeft(board->tiles, sr, sc, &xCounter, &oCounter, player);
                                            }
                                            else{
                                                valid = DownLeft(board->tiles, sr, sc, &xCounter, &oCounter, player);
                                            }
                                        break;
                                        case 3:
                                            playing = false; //ends current game
                                            valid = true;
                                            
                                        break;                                    
                                        default:
                                            printf("Invalid choice.\n");
                                        break;
                                    }
                                }
                                else if(board->tiles[sr][sc] == (player -32)){
                                    printf("\nMovement choices:\n");
                                    printf("1. Up Right\n");
                                    printf("2. Down Right\n");
                                    printf("3. Up Left\n");
                                    printf("4. Down Left\n");
				    printf("5. Exit game\n");
                                    printf("Your choice: ");
                                    scanf(" %d", &pChoice);
                                    switch(pChoice){
                                        case 1:
                                            valid = UpRight(board->tiles, sr, sc, &xCounter, &oCounter, player);
                                        break;
                                        
                                        case 2:
                                            valid = DownRight(board->tiles, sr, sc, &xCounter, &oCounter, player); 
                                        break;
    
                                        case 3:
                                                valid = UpLeft(board->tiles, sr, sc, &xCounter, &oCounter, player);
                                        break;
    
                                        case 4:
                                                valid = DownLeft(board->tiles, sr, sc, &xCounter, &oCounter, player);
                                        break;
					
					case 5:
                                                playing = false; //ends current game
                                            	valid = true;
					break;
                                        
                                        default:
                                            printf("Invalid choice.\n");
                                        break;
                                    }
                                }
                                else{
                                    printf("invalid space\n");
                                }
                         }
                         if(player == 'x'){
                             player = 'o';
                         }
                         else{
                             player = 'x';
                         }
                        valid = false;
                    }
			
                }
                break;

            case 2: // Display Stats
               char *stats = GetScoreBoard();
                printf("Current Scores: \n%s", stats);
                break;

            case 3: // reset statistics
                char *reset = resetScoreBoard();
                if(reset != NULL){
                    printf("%s\n", reset);
                }	
                break;

            case 4: // Exit
                freeBoard(board);		
                return 0;

            default:
                printf("Not a valid choice pick again");
                break;
        }
    }

    return 0; // This line is not reached due to return above
}
