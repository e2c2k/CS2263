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
                char p1[25];
                char p2[25];
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

