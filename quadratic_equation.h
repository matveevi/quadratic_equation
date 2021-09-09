#include <stdio.h>
#include <math.h>
#include "assert.h"
#define EXP 1.0e-10

int Solve(double first_par, double second_par, double third_par, double* x1, double* x2) {

    assert(isfinite(first_par));
    assert(isfinite(second_par));
    assert(isfinite(third_par));

    assert(x1 != NULL);
    assert(x2 != NULL);

    double discriminant = 0;
    discriminant = second_par * second_par - 4 * first_par * third_par;

    assert(isfinite(discriminant));

    double sqrt_of_discriminant = 0.;
    if (discriminant < EXP && discriminant > -EXP) {
        assert(first_par >= EXP || first_par <= EXP);
        
        *x1 = (- second_par / (2 * first_par));
        if (*x1 < EXP && *x1 > -EXP) {
            *x1 = 0.;
        }

        return 1;
    } else if (discriminant < -EXP) {
        return 0;
    } else {
        sqrt_of_discriminant = sqrt(discriminant);
        
        assert(isfinite(sqrt_of_discriminant));
        assert(first_par >= EXP || first_par <= EXP);

        *x1 = (-second_par - sqrt_of_discriminant) / (2 * first_par);
        *x2 = (-second_par + sqrt_of_discriminant) / (2 * first_par);

        if (*x1 < EXP && *x1 > -EXP) {
            *x1 = 0.;
        }
        if (*x2 < EXP && *x2 > -EXP) {
            *x2 = 0.;
        }
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