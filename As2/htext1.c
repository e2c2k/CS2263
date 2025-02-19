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
	int dnp = 0;
	printf("\n");
	do{
		if(curr == '<'){
			insideTag = 1;
		}
		else if(curr == '>'){
			insideTag = 0;
			
		}
		else if(curr == '\n'){
			dnp = 1;
		}
		else if(insideTag == 0 && dnp == 0){
			printf("%c", curr);
		}
		if(dnp == 1){
			printf(" ");
			dnp = 0;
		}
	}
	while((curr = fgetc(inFile)) != EOF);
	printf("\n");
	fclose(inFile);
	return EXIT_SUCCESS;
}
