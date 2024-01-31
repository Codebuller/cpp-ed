#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]){
    
    char* ar = malloc(10);
    int* ptr_int = malloc(sizeof(int));
    short* ptr_short = malloc(7 * sizeof(short));
    
    free(ar);
    free(ptr_int);
    free(ptr_short);

    return 0;
}