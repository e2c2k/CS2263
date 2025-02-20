#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void printTags(FILE *file) {
    char lines[1024];
    char tags[1024];
    int tagIndex = 0;
    bool inTag = false;
    int inComment = 0;

    while (fgets(lines, sizeof(lines), file)) {
        for (int i = 0; lines[i]; i++) {
            if (inComment) {
                if (lines[i] == '-' && lines[i+1] == '-' && lines[i+2] == '>') {
                    inComment = 0;
                    i += 2;
                }
                continue;
            }

            if (lines[i] == '<' && lines[i+1] == '!' && 
                lines[i+2] == '-' && lines[i+3] == '-') {
                inComment = 1;
                i += 3;
                continue;
            }

            if (lines[i] == '<') {
                inTag = true;
                tagIndex = 0;
                tags[tagIndex++] = lines[i];
            }
            else if (lines[i] == '>' && inTag) {
                tags[tagIndex++] = lines[i];
                tags[tagIndex] = '\0';
                printf("%s\n", tags);
                inTag = false;
            }
            else if (inTag) {
                tags[tagIndex++] = lines[i];
            }
        }
    }
}

int main(int argc, char *argv[]) {

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    printTags(file);
    fclose(file);
    return 0;
}