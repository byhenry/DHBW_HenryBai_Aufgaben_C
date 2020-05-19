#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "complex.h"


int main(){
    complex_number first_num;
    complex_number second_num;
    complex_number res;
    
    char entry1[64], entry2[64];
    char way, show, again, buffer;
    char delimiter[] = "+i";

    printf("*****************COMPLEX NUMBERS CALCULATOR******************\n");
    do{
        printf("*ENTER FIRST NUMBER:\t\t\t\t\t\t[ a+bi / a+-bi ]\n");
        scanf("%s", &entry1);

        first_num.re = atof(strtok(entry1, delimiter));
        first_num.im = atof(strtok(NULL, delimiter));

        printf("*ENTER SECOND NUMBER:\t\t\t\t\t\t[ a+bi / a+-bi ]\n");
        scanf("%s", &entry2);

        second_num.re = atof(strtok(entry2, delimiter));
        second_num.im = atof(strtok(NULL, delimiter));

        int stop = 0;
        printf("*addition / subtraction / multiplication/ division:\t\t[ + , - , * , / ]\n");
        do{
            scanf("%c", &way);
            switch(way){
                case '+': res = com_sum(first_num, second_num); stop = 1; break;
                case '-': res = com_sub(first_num, second_num); stop = 1; break;
                case '*': res = com_mul(first_num, second_num); stop = 1; break;
                case '/': res = com_div(first_num, second_num); stop = 1; break;
            }
        }while(stop == 0);

        stop = 0;
        printf("*karthesisch / euler / polar:\t\t\t\t\t[ k / e / p ]\n");
        do{
            scanf("%c", &show);
            
            switch(show){
                case 'k': print_comk(res); stop = 1; break;
                case 'e': print_come(res); stop = 1; break;
                case 'p': print_comp(res); stop = 1; break;
            }

        }while(stop == 0);

        printf("\n*AGAIN:\t\t\t\t\t\t\t\t[ n / j ]\n");
        scanf("%c", &buffer);
        scanf("%c", &again);

    }while(!(again == 'n' || again == 'N'));
    return 0;
}