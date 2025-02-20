//fgets
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(int argc, char * argv[]){
FILE *fptr;
int numLine = 0;
char oneLine[81]; // does not need to be 81.
if(argc < 2){
printf("need to provide the files name");
return EXIT_FAILURE;
}
fptr = fopen(argv[1], "r");
if(fptr == NULL){
printf("fopen fail \n");
return EXIT_FAILURE;
while(fgets(oneLine, 81, fptr) != NULL){
numLine++;
}
fclose(fptr);
