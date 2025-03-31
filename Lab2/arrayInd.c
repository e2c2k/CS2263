#include <stdio.h>
#include <stdio.h>

int main(){


    int arrindex (int a[], int * p){
      
        int temp = (int)(p - a);
        
        return temp;
    }
    int arr[] = {10, 11, 12, 13, 14, 15, 16};
    for (int i; i < sizeof(arr)/sizeof(arr[0]); i ++){
        printf("%d %d \n", i, arrindex( arr, & arr[i]));
        }
}
