#include <stdio.h>
#include <stdlib.h>



void UpdateScoreBoard(int player_number) {
    int player1 = 0;
    int player2 = 0;
    char * filepath = "/home1/ugrads/b7gy7/CS2263/FinalTesting/scoreboard.txt"; 
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

char * GetScoreBoard() {
    char * filepath = "/home1/ugrads/b7gy7/CS2263/FinalTesting/scoreboard.txt"; 
    FILE *file = fopen(filepath, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filepath);
        return NULL;
    }
    int player1 = 0;
    int player2 = 0;
    fscanf(file, "%d,%d", &player1, &player2);
    fclose(file);
    char * result = (char *)malloc(100);
    sprintf(result, "Player1: %d, Player2: %d", player1, player2);
    return result;
}

char * resetScoreBoard() {
    char * filepath = "/home1/ugrads/b7gy7/CS2263/FinalTesting/scoreboard.txt"; 
    FILE *file = fopen(filepath, "w");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filepath);
        return NULL;
    }
    fprintf(file, "0,0");
    fclose(file);
    return "Scoreboard reset";
}
