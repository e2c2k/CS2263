#include <stdio.h>
#include <stdlib.h>



void update_player_wins(int player_number) {
    int player1 = 0;
    int player2 = 0;
    char * filepath = "/Users/michaeldrost/CS2263/Final_Project_Folder/scoreboard.txt"; 
    // read existing values 
    FILE *file = fopen(filepath, "r");
    if (file) {
        fscanf(file, "%d,%d", &player1, &player2);
        fclose(file);
    }
    // increment the winnner
    if (player_number == 1) {
        player1++;
    } else if (player_number == 2) {
        player2++;
    } else {
        fprintf(stderr, "Invalid player number: %d (use 1 or 2)\n", player_number);
        return;
    }

    //update value
    file = fopen(filepath, "w");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filepath);
        return;
    }
    
    fprintf(file, "%d,%d", player1, player2);
    fclose(file);

    printf("score:  Player1: %d, Player2: %d\n", player1, player2);
}

int main (){
    update_player_wins(2);
    return 0;
}