#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<stdbool.h>
int isFib(int i);
int isPrime(int i);
bool isSqr(int j);
int main(int argc, char * * argv)
{
	printf("Enter a testing integer: ");
    	int x1;
    	scanf("%d",&x1);
	printf("Is your number apart of the fibonacci seq.? \n");
	if(isFib(x1) == 1) //RV
	{
	//Return Line
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	printf("Is your number a prime number? \n");
	if(isPrime(x1) == 1) // RV
	{
		//Return Line
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
   	return EXIT_SUCCESS; 
}

bool isSqr(int j){
	int x = sqrt(j);
    	return (x * x == j);
}
int isFib(int i){
	bool a = isSqr((5 * (i * i) + 4))  ||  isSqr((5 * (i * i) - 4)); //RV
	if(a == true){ //Return Line
		return 1;
	}
	return 0;
}
int isPrime(int i){
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


