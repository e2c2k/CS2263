#include <stdio.h>
#include <stdlib.h>

static int isPrime(int i){
    int div = 1; 
    int factors = 0; 
    while(div < i) { 
        if(i%div == 0){ 
            factors++; 
        } 
        div++;
    } 
    if(factors == 1){ 
        return 1; 
    } 
    return 0; 
} 

