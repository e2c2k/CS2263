#include <stdio.h> 
#include <stdlib.h>
#include "isFib.c"
int main() {
    printf("Enter an Integer: ");
    int num;
    scanf("%d",&num);
    if (isFib(num)) {
        printf("%d is a Fibonacci number.\n", num);
    } else {
        printf("%d is not a Fibonacci number.\n", num);
    }
    return 0;
}