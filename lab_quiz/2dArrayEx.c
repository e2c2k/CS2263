#include <stdio.h>
#include <stdlib.h>

int main(){
int rows;
int cols;
int **array = (int **)malloc(rows * sizeof(int *));
if array == NULL){
printf("memory allocation failed");
return 1;
}
for(int i = 0; i < rows; i++){
array[i] = (int *)malloc(cols * sizeof(int));
if(array[i] == NULL){
printf("Memory allocation failed");
for(int j = 0; j < i; j++){
free(array[j]);
}
free(array);
return 1;
}
}
// free the array
for(int i = 0; i < rows; i++){
free(array[i]);
}
free(array);
return 0;
