int main(){
FILE *fptr = fopen("rvexample.txt", "r");
int number;
char word[100];
int result;
result = fscanf(fptr, "%d %99s", &number, word);
