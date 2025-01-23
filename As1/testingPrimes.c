#include <stdio.h>
#include <stdlib.h>
#include "isPrime.c"
int main(int argc, char* argv[]){
    printf("Enter an Integer: ");
    int n;
    scanf("%d",&n);
    
    if (isPrime(n)==1){
        printf("%d is a prime number\n",n);
    }else{
        printf("%d is not prime\n",n);
    }
    return EXIT_SUCCESS;
}
