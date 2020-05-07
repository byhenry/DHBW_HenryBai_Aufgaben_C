//Henry Bai
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
    for(int x = 0; x < len; x++){
        for(int y = 0; y < len; y++){
            printf("  %d", mat[x, y]);
        }
        printf("\n");
    }
    return 0;
}