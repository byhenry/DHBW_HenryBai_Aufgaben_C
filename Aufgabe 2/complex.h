#ifndef COMPLEX_H_
#define COMPLEX_H_

typedef struct{
    double re;
    double im;
}complex_number;

complex_number com_sum(complex_number, complex_number);
complex_number com_sub(complex_number, complex_number);
complex_number com_mul(complex_number, complex_number);
complex_number com_div(complex_number, complex_number);

void print_comk(complex_number);
void print_come(complex_number);
void print_comp(complex_number);

#endif