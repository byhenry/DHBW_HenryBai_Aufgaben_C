//Henry Bai
#include <stdio.h>
#include <stdlib.h>

int main(){

    int lenx = 5;
    int leny = 5;

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

    double** mat = malloc(sizeof(double) * lenx);
    for(int i = 0; i < lenx; i++){
        mat[i] = malloc(sizeof(double) * leny);
    }
    
    printf("Values of matrix:\n");
    for(int x = 0; x < lenx; x++){
        for(int y = 0; y < leny; y++){
            printf("  %d", mat[x, y]);
        }
        printf("\n");
    }
    return 0;
}