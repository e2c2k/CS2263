#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){
	FILE *inFile;
	inFile = fopen(argv[1], "r");
	if(inFile == NULL){
		perror("Error opening file");
		return EXIT_FAILURE;
	}
	int curr;
	int insideTag = 0;
	printf("\n");
	do{
		if(curr == '<'){
			insideTag = 1;
			if(fgetc(inFile) == '!'){
			    do{
			        insideTag = 1;
			    }while(fgetc(inFile) != '>');
			}
		}
		if(insideTag == 1){
			printf("%c", curr);
		}
		if(curr == '>'){
			printf("\n");
			insideTag = 0;
		}
    }while((curr = fgetc(inFile)) != EOF);
	printf("\n");
	fclose(inFile);
	return EXIT_SUCCESS;
}
