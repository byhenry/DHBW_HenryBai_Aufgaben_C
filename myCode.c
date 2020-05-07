#include <stdio.h>
#include <stdlib.h>

int main(){

    int len = 5;

    /*double* vec = malloc(sizeof(double) * len);

    printf("Values of vec: \n");
    for(int i = 0; i < len; i++){
        printf("value %d = %d\n", i, vec[i]);
    }

    printf("\naddress of vec hex: \n");
    for(int i = 0; i < len; i++){
        printf("mem(ptr[i]) = %p\n", &vec[i]);
    }

    printf("\nin dec: \n");
    for(int i = 0; i < len; i++) printf("mem(ptr[i]) = %d\n", &vec[i]);
*/

    double** mat = malloc(sizeof(double) * len);
    for(int i = 0; i < len; i++){
        mat[i] = malloc(sizeof(double) * len);
    } 
    
    printf("Values of matrix:\n");
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++) printf("  %d", mat[i, j]);
        printf("\n");
    }
    return 0;
}