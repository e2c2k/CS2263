#include <stdio.h> 
#include <stdlib.h>

int main() {
    int num = 57; 
    if (isFib(num)) {
        printf("%d is a Fibonacci number.\n", num);
    } else {
        printf("%d is not a Fibonacci number.\n", num);
    }
    return 0;
}