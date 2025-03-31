#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * * argv){

      trib(20);

}
    void trib(int i){
        int a=1;
        int b=0;
        int c=0;
        int temp = 0;
        
        for(int j = 1; j <= i; j++){
            if(j-1 == 0){
                printf("%d\n", temp);
            }
            if(j%2 == 0){
              printf("%d\n", temp);
            }
            temp = a+b+c;
            c = b;
            b = a;
            a = temp;
    }  
}      
