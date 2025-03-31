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
		
		if(insideTag == 1 && dnp == 1){
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

/*
Description:
The program takes in a file, assigned to inFile by argv[1]. This program only reads from it.
The program has 3 varables, curr, insideTag, and dnp. 
curr is the character we're currently at.
insideTag identifies if we're inside the tag paramiters or not, 1 if we are, 0 if we aren't.
dnp is used to allocate new lines as spaces to make the format of the result a bit more clear.
by using a do while loop, this allows us to check all of the characters without exception.
*/
