#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include board.c;
#include move.c;
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
                Board board createBoard();
                initializeBoard(&board);
                boolean playing = true;
                int xCounter = 12;
                int oCounter = 12;
                int sr;
                int sc;
                int pChoice;
                char player = 'X'
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
                    printf("player %c make your turn.");
                    if(player == 'X'){
                        player = 'O'
                    }
                    else{
                        player = 'X'
                    }
                    printf("Select the row of the piece to move: ");
                    scanf("%d", sr);
                    printf("Select the column of the piece to move: ");
                    scanf("%d", sc);
                    if(board->tiles[sr][sc] == 'x' || board->tiles[sr][sc] == 'o'){

                    }
                    else if(board->tiles[sr][sc] == 'x' || board->tiles[sr][sc] == 'o'){

                    }
                    else{
                        printf("invalid space");
                    
                }
                break;

            case 2: // Display Stats
                // displays the stats like wins , Another method to be made later
                break;

            case 3: // Exit
                // A free Method to be made				
                return 0;

            default:
                printf("Not a valid choice pick again");
                break;
        }
    }

    return 0; // This line is not reached due to return above
}

