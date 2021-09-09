#include <stdio.h>
#include <math.h>
#define EXP 1.0e-10

int NumberOfSolutions(double discriminant_tmp) {
    if (discriminant_tmp < EXP && discriminant_tmp > -EXP) {
        return 1;
    } else if (discriminant_tmp < -EXP) {
        return 0;
    } else {
        return 2;
    }
}

int LinearHomogeneousEquation(int second_par, int third_par) {
    if (second_par == 0 && third_par == 0) {
        return 2;
    } else if (second_par == 0) {
        return 0;
    } else {
        return 1;
    }
}