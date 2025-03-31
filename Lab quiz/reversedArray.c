#include <stdlib.h>
#include <stdio.h>

int main (){
    int *arr;
    arr = malloc(sizeof(int) * 7);
    int size = 7;
    for(int i = 1; i < size + 1; i++){
        arr[i] = i;
        printf("%d\n", arr[i]);   
    }
    printf("\n");
    reverseArray(arr, size);
    free(arr);
    return 0;
}
int reverseArray(int *arr, int size){
    int end = size;
        for(int i = 0; i < size; i++){
            arr[i] = end--;   
            printf("%d\n", arr[i]);
        }
    }
