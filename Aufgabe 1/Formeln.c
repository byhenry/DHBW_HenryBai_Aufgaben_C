#include <math.h>

double func(double x){
    return pow((x - 3), 2);
}

double der(double x){
    return 2 * (x - 3);
}