#include <stdlib.h>
#include <stdio.h>
#include "HA05_rhsLib.h"

#define NUMOFSTATES 2
#define NUMOFCOMMANDS 3
/*******************************************************
* NAME: HA05_main.c (main) 
*
* AUTHOR: jannik wiessler // henry bai
*
* DATE: 2020-06-09
*
* DESCRIPTION:  Implementation of a simple explicit euler method. 
*               
*
* DEPENDENCIES: 
*   >> HA05_rhsLib.c
*   >> HA05_rhsLib.h
*
* INFO: For DHBW use only.
*   >> Modelling of spring damper system
*   >> Simulation with simple euler foreward method
*
**/
int main(){

    char * commandsForGnuplot_msd[] = {"set title \"Results of simulation: MSD\"", "set xlabel \"time in s\"",
    "plot 'results.txt' using 1:2 title 'position', 'results_msd.txt' using 1:3 title 'speed'"};

    char * commandsForGnuplot_bb[] = {"set title \"Results of simulation: BALL\"", "set xlabel \"time in s\"",
    "plot 'results.txt' using 1:2 title 'position', 'results_bb.txt' using 1:3 title 'speed'"};

    FILE* fp;
    fp = fopen("results_msd.txt", "w");
    if(fp == NULL) {
	    printf("Datei konnte NICHT geoeffnet werden.\n");
        return -1;
    }

    double rhs[NUMOFSTATES]; // create rhs
    double y_old[NUMOFSTATES]; // state vector
    double y_new[NUMOFSTATES]; // state vector

    double h = 2e-2; // stepsize for integrator
    double simTime = 12; // time of simulation in seconds

    // init all vecs to zero //
    for(int i = 0; i < NUMOFSTATES; i++){
        rhs[i] = 0;
        y_old[i] = 0;
        y_new[i] = 0;
    }

    // init x and v //
    y_old[0] = 1; // location 
    y_old[1] = 0; // speed

    // euler forward //
    for(int i = 0; i < simTime/h; i++){

        fprintf(fp,"%lf %lf %lf\n", i * h, y_old[0], y_old[1]);
        RHS_MSD(rhs, y_old);
        y_new[0] = y_old[0] + h * rhs[0];
        y_new[1] = y_old[1] + h * rhs[1];
        y_old[0] = y_new[0];                            //entweder hab ich was falsch verstanden, oder die Unterteilung in old und new ist überflüssig, weil man das gewünschte Ergebnis auch einfach durch die richtige Reihenfolge bekommt
        y_old[1] = y_new[1];
    }

    fclose(fp);

    //__________________________________________________________________
    //---------------------------bouncy ball----------------------------
    fp = fopen("results_bb.txt", "w");
    if(fp == NULL) {
	    printf("Datei konnte NICHT geoeffnet werden.\n");
        return -1;
    }
    
    
    for(int i = 0; i < NUMOFSTATES; i++){
        rhs[i] = 0;
        y_old[i] = 0;
        y_new[i] = 0;
    }

    // init x and v //
    y_old[0] = 1; // location 
    y_old[1] = 0; // speed

    // euler forward //
    for(int i = 0; i < simTime/h; i++){

        fprintf(fp,"%lf %lf %lf\n", i * h, y_old[0], y_old[1]);
        myRHS_Ball(rhs, y_old);
        y_new[0] = y_old[0] + h * rhs[0];               // soll das so sein, dass sich die Position des Balls nicht mehr ändert, aber die Geschwindigkeit schon?
        y_new[1] = y_old[1] + h * rhs[1];
        y_old[0] = y_new[0];
        y_old[1] = y_new[1];
    }

    fclose(fp);


    printf("finished...\n");
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    for (int i=0; i < NUMOFCOMMANDS; i++) fprintf(gnuplotPipe, "%s \n", commandsForGnuplot_msd[i]); //Send commands to gnuplot one by one.

    gnuplotPipe = popen ("gnuplot -persistent", "w");
    for (int i=0; i < NUMOFCOMMANDS; i++) fprintf(gnuplotPipe, "%s \n", commandsForGnuplot_bb[i]);
    //pclose(gnuplotPipe); wenn ich versuche die Pipe am ende zu schließen, dann wird das 2. Diagramm erst gezeigt, wenn ich das erste schließe. Hat es außerdem einen Grund, warum du die nicht schließt am Ende?
return 0;
}