#include "quadratic_equation.h"
#include "assert.h"
#include "float.h"

bool IsZero(double num) {
    return num > -DBL_EPSILON && num < DBL_EPSILON;
}

int SolveLinearEquation(double first_par, double second_par, double* x) {
    assert(isfinite(first_par));
    assert(isfinite(second_par));

    assert(x != nullptr);

    if (IsZero(first_par) && IsZero(second_par)) {
        return ANY_ROOTS;
    } else if (IsZero(first_par)) {
        return 0;
    } else {
        *x = - second_par / first_par;
        if (IsZero(*x)) {
            *x = 0.;
        }
        return 1;
    }
}

int SolveQuadraticEquation(double first_par, double second_par, double third_par, double* x1, double* x2) {
    assert(isfinite(first_par));
    assert(isfinite(second_par));
    assert(isfinite(third_par));

    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(x2 != x1);

    if (first_par == 0) {
        return SolveLinearEquation(second_par, third_par, x1);
    }

    double discriminant = 0;
    discriminant = second_par * second_par - 4 * first_par * third_par;

    assert(isfinite(discriminant));

    double sqrt_of_discriminant = 0.;
    if (IsZero(discriminant)) {   
        assert(!IsZero(first_par));

        *x1 = (-second_par / (2 * first_par));
        if (IsZero(*x1)) {
            *x1 = 0.;
        }
        return 1;
    } else if (discriminant < -DBL_EPSILON) {
        return 0;
    } else {
        sqrt_of_discriminant = sqrt(discriminant);
        
        assert(isfinite(sqrt_of_discriminant));
        assert(!IsZero(first_par));

        *x1 = (-second_par - sqrt_of_discriminant) / (2 * first_par);
        *x2 = (-second_par + sqrt_of_discriminant) / (2 * first_par);

        if (IsZero(*x1)) {
            *x1 = 0.;
        }
        if (IsZero(*x2)) {
            *x2 = 0.;
        }
        return 2;
    }
}