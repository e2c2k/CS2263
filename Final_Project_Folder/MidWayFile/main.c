#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Move.c"
3INCLUDE "txtFiles.c"
#define BOARD_SIZE 8
int main(int argc, char ** argv[]){
    int choice;
    printf("Welcome to Checkers!\n");

    while (1) {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Start New Game\n");
        printf("2. Display Stats \n");
        printf("3. Exit\n");
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
                int move = 0;
                bool valid = false;
                while(playing){
                    printBoard(board);
                    if(xCounter == 0){
                        printf(" O's win!\n");
                        //save to document
                        playing = false;
                    }
                    if(oCounter == 0){
                        printf("X's win!\n");
                        //save to document
                        playing = false;
                    }
                    printf("player %c make your turn.\n", player);
                    while(!valid){
                        printf("Select the row of the piece to move: ");
                        scanf(" %d", &sr);
                        printf("Select the column of the piece to move: ");
                        scanf(" %d", &sc);
                        if(board->tiles[sr][sc] == 'x' || board->tiles[sr][sc] == 'o'){
                            printf("\nMovement choices:\n");
                            printf("1. Diagonal right\n");
                            printf("2. Diagonal left\n");
                            printf("3. Exit game\n");                            
                            printf("Your choice: ");
                            scanf(" %d", &pChoice);
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
                                        freeBoard(board); // free board so no memory leak :)
                                        playing = false; //ends current game
                                        
                                    break;                                    
                                    default:
                                        printf("Invalid choice.\n");
                                    break;
                                }
                            }
                            else if(board->tiles[sr][sc] == 'X' || board->tiles[sr][sc] == 'O'){
                                printf("\nMovement choices:\n");
                                printf("1. Up Right\n");
                                printf("2. Down Right\n");
                                printf("3. Up Left\n");
                                printf("4. Up Right\n");
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
                break;

            case 2: // Display Stats
                // displays the stats like wins , Another method to be made later
                break;

            case 3: // Exit
                freeBoard(board);		
                return 0;

            default:
                printf("Not a valid choice pick again");
                break;
        }
    }

    return 0; // This line is not reached due to return above
}

