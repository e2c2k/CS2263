#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getScoreboardPath(char *buffer, size_t size) {
    snprintf(buffer, size, "../scoreboard.txt");
}

void ensureFileExists(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        printf("File not found, creating a new one...\n");
        file = fopen(filepath, "w");
        if (file) {
            fprintf(file, "0,0");
            fclose(file);
        } else {
            fprintf(stderr, "Error creating file: %s\n", filepath);
        }
    } else {
        fclose(file);  // If file exists, just close it
    }
}

void UpdateScoreBoard(int player_number) {
    int player1 = 0;
    int player2 = 0;
    char filepath[256]; 
    getScoreboardPath(filepath, sizeof(filepath));
    ensureFileExists(filepath);

    FILE *file = fopen(filepath, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filepath);
        return;
    }
    
    fscanf(file, "%d,%d", &player1, &player2);
    fclose(file);

    // Increment the winner
    if (player_number == 1) {
        player1++;
    } else if (player_number == 2) {
        player2++;
    } else {
        fprintf(stderr, "Invalid player number: %d (use 1 or 2)\n", player_number);
        return;
    }

    file = fopen(filepath, "w");
    if (!file) {
        fprintf(stderr, "Error opening file for writing: %s\n", filepath);
        return;
    }
    fprintf(file, "%d,%d", player1, player2);
    fclose(file);

    printf("Updated score: Player1: %d, Player2: %d\n", player1, player2);
}

char * GetScoreBoard() {
    char filepath[256];
    
    getScoreboardPath(filepath, sizeof(filepath));
    printf("Generated file path: %s\n", filepath);

    ensureFileExists(filepath);

    FILE *file = fopen(filepath, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filepath);
        return NULL;
    }

    int player1 = 0;
    int player2 = 0;
    fscanf(file, "%d,%d", &player1, &player2);
    fclose(file);

    char *result = (char *)malloc(100);
    sprintf(result, "Player1: %d, Player2: %d", player1, player2);
    return result;
}

char * resetScoreBoard() {
    char filepath[256];
    
    getScoreboardPath(filepath, sizeof(filepath));
    printf("Generated file path: %s\n", filepath);

    ensureFileExists(filepath);

    FILE *file = fopen(filepath, "w");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filepath);
        return NULL;
    }
    fprintf(file, "0,0");
    fclose(file);
    return "Scoreboard reset";
}

