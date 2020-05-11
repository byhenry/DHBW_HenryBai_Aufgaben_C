/*
Newton-Raphson-Verfahren
11.05.2020
Henry Bai
*/
#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include "Formeln.h"

int main(){
int len = 1000;
double start_val = 5;
double values[3][len];
values[0][0] = 0;
values[1][0] = start_val;
values[2][0] = func(start_val);
printf("START VALUES\nROW: %lf\tX: %lf\tY:%lf\n\n", values[0][0], values[1][0], values[2][0]);

int row = 0;
do{
    row++;
    values[0][row] = row;
    values[1][row] = values[1][row - 1] - func(values[1][row - 1]) / der(values[1][row - 1]);
    values[2][row] = func(values[1][row]);
    printf("ROW: %lf\tX: %lf\tY:%lf\n", values[0][row], values[1][row], values[2][row]);

} while (row < len && sqrt(pow(values[2][row], 2)) > 0.0000000000000001);


} 