#include <stdlib.h>
#include <stdio.h>

int main (int argc, char * * argv){
    int val = 0;
    printf("enter a number:");
    scanf("d", val);
    int *arr;
    arr = malloc(sizeof(int) * 4);
    int temp = 0;
    while(scanf("d", temp) == -1 ){   
        printf("%d", temp);
        printf("enter a number:");
        //scanf("d", temp);  
        realloc(arr, sizeof(int) * 2);
        //infinite loop as of right now 
    }
    if( val == -1){
    //printf(current array);
    free(arr);
    printf("EOF");
    return 0;
}
