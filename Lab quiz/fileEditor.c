#include <stdlib.h>
#include <stdio.h>

int main (int argc, char * * argv){
    
    FILE *file;
    int val;
    file = fopen(argv[1], "r");//could not get it to not say segmentation dump
    printf("Enter destination file name: ");
    scanf("%s", file);
    printf("enter number of lines to append:" );
    scanf("%d", val);
    
    while(fscanf(file, "%c", &val) == 1){
    printf("Success");
    }
    if(file == NULL){
        perror("FAILED");
        return EXIT_FAILURE;
    }
    fclose(file);
    return EXIT_SUCCESS;
}
