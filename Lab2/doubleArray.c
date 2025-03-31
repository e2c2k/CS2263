#include <stdio.h>
#include <stdio.h>
//#include <String>

int main(){
    int arr1[] = {10, 11, 12, 13, 14, 15, 16};
    int * iptr = arr1;
    int n = *(&arr1 + 1) - arr1;
    for(int i = 0; i < n; i++){
        printf("%d ,", i);
        printf("%d ,",arr1[i]);
         printf("%p ,", iptr);
         printf("%d \n",*iptr);
         *iptr++;
         }
}
