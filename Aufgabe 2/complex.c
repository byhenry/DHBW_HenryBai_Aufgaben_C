#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{         //ich hab lange gesucht aber nicht gefunden, wie man es richtig definiert, 
    double re;          //ob nur in der h-Datei oder nur in der c-Datei und das einzige das bei mir funktioniert hat ist die Lösung!
    double im;
}complex_number; // JW 2020-05-20: passt doch :-)

complex_number com_sum(complex_number one, complex_number two){
    complex_number res;
    res.re = one.re + two.re;
    res.im = one.im + two.im;
    return res;
}

complex_number com_sub(complex_number one, complex_number two){
    complex_number res;
    res.re = one.re - two.re;
    res.im = one.im - two.im;
    return res;
}

complex_number com_mul(complex_number one, complex_number two){
    complex_number res;
    res.re = one.re * two.re - one.im * two.im;
    res.im = one.re * two.im + one.im * two.re;
    return res;
}

complex_number com_div(complex_number one, complex_number two){
    complex_number res;
    res.re = (one.re * two.re - one.im * -two.im) / (two.re * two.re + two.im * two.im);
    res.im = (one.re * -two.im + one.im * two.re) / (two.re * two.re + two.im * two.im);
    return res;
}

void print_comk(complex_number numb){ 
    printf("\n*RESULT: \n\tz = %.3lf + %.3lfi\n", numb.re, numb.im);
}

void print_come(complex_number numb){
    double len = sqrt(numb.re * numb.re + numb.im * numb.im);
    double angle;
    if(numb.re > 0){
        angle = atan(numb.im / numb.re);
    };
    if(numb.re < 0 && numb.im >= 0){
        angle = atan(numb.im / numb.re) + M_PI;
    };
    if(numb.re < 0 && numb.im < 0){ 
        angle = atan(numb.im / numb.re) - M_PI;
    };
    if(numb.re == 0 && numb.im > 0){ 
        angle = M_PI / 2;
    };
    if(numb.re == 0 && numb.im < 0){ 
        angle = - M_PI / 2;
    };
     
    printf("\n*RESULT: \n\tz = %.3lfe^(%.3lfi)\n", len, angle);
}

void print_comp(complex_number numb){
    double len = sqrt(numb.re * numb.re + numb.im * numb.im);
    double angle;
    if(numb.re > 0){
        angle = atan(numb.im / numb.re);
    };
    if(numb.re < 0 && numb.im >= 0){
        angle = atan(numb.im / numb.re) + M_PI;
    };
    if(numb.re < 0 && numb.im < 0){ 
        angle = atan(numb.im / numb.re) - M_PI;
    };
    if(numb.re == 0 && numb.im > 0){ 
        angle = M_PI / 2;
    };
    if(numb.re == 0 && numb.im < 0){ 
        angle = - M_PI / 2;
    };
     
    printf("\n*RESULT: \n\tz = %.3lf(cos(%.3lf) + isin(%.3lf))\n", len, angle, angle);
}