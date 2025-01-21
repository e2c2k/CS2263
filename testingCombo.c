#include <stdio.h>
#include <stdlib.h>
#include "isPrime.c"
int isFib(int i);
int main(int argc, char * * argv)
{
    printf("Enter a lower bound integer: ");
    int x1;
    scanf("%d",&x1);
        printf("Enter a upper bound Integer: ");
    int x2;
    scanf("%d",&x2);
	void printRange(int x1, int x2)
	{
	int current = x1;
		while(current <= x2)
		{
			if(isPrime(current) == 1 && isFib(current) == 1)
			{
				printf("%d\n", current);
			}
			current++;
		}
	}
	printRange(x1, x2);
	return EXIT_SUCCESS;
}
