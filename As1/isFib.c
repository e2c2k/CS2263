#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<stdbool.h>

static bool isSqr(int j){
    int x = sqrt(j);
    return (x * x == j);
}
static int isFib(int i){
    bool a = isSqr((5 * (i * i) + 4))  ||  isSqr((5 * (i * i) - 4));
	if(a == true){
	    return 1;
	}
	return 0;
}