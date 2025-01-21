#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<stdbool.h>

bool isSqr(int j){
    int x = sqrt(j);
    return (x * x == j);
}
int isFib(int i){
    bool a = isSqr((5 * (i * i) + 4))  ||  isSqr((5 * (i * i) - 4));
	if(a == true){
	    return 1;
	}
	return 0;
}