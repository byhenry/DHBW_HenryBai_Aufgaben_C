#include <stdlib.h>
#include <stdio.h>

void RHS_MSD(double*rhs, double*y){

    double m = 1.0; // mass of object
    double c = 5.0; // spring constant
    double d = 4.0; // damper constant

    double x = y[0]; // position
    double v = y[1]; // speed

    rhs[0] = v;
    rhs[1] = -((d / m) * v + (c / m) * x );
}

void myRHS_Ball(double*rhs, double*y){

    double x = y[0]; // position
    double v = y[1]; // speed

    double m = 1.0; // mass of object
    double g = 9.81; // gravity constant
    double c = 5.0; // feder constant
    double rhoL = 1; // density of air
    double cW = 3; // objects cW value
    double A = 2.5; // objects area 

    double forceSign = 1; // sign for air resistance (drag)
    if (v > 0) forceSign = -1;

    rhs[0] = v;
    rhs[1] = -(g+(c/m)*x) + 1.0/(2.0*m)*rhoL*cW*A*v*v*forceSign;

}

