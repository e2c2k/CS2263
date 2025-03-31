#include <stdio.h>
#include <stdlib.h>
void dummy_frame()
{
return;
}
int main(int argc, char * * argv)
{
double size = 9001;
int * a;
a = malloc(sizeof(int) * 10);

int * b;
b = malloc(sizeof(double) * 500);
b = realloc(b, sizeof(double) * size);

int i;
    for (i=0; i<size; i++){
    a[i] = i;
    printf("main: a = %d %p \n", a[i], &a[i]);
    }
    a = realloc(a, sizeof(int) * 7);
    for(int j = 0; j < 7; j++){
    a[j] = j;
    printf("main: (new)a = %d %p \n", a[j], &a[j]);
    
    }
    dummy_frame();
    //free(a);
    return EXIT_SUCCESS;
}
