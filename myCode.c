#include <stdio.h>
#include <stdlib.h>

int main(){

    int len = 5;

    int* vec = malloc(sizeof(int) * len);
    
    /*for(int i = 0; i < len; i++){
        vec[i] = i;
    }*/

    printf("Values of vec: \n");
    for(int i = 0; i < len; i++){
        printf("value %d = %d\n", i, vec[i]);
    }

    printf("addresses of vec: \n");
    for(int i = 0; i < len; i++){
        printf("address %d = %d\n", i, &vec[i]);
    }

}