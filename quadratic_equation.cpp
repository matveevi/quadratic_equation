#include "quadratic_equation.h"
#include "assert.h"

const double DBL_EPSILON = 1.0e-10;

bool CompareDoublesWZero(double num) {
    return num > -DBL_EPSILON && num < DBL_EPSILON;
}

int SolveLinearEquation(double second_par, double third_par, double* x1) {
    assert(isfinite(second_par));
    assert(isfinite(third_par));

    assert(x1 != NULL);

    if (CompareDoublesWZero(second_par) && CompareDoublesWZero(third_par)) {
        return -1;
    } else if (CompareDoublesWZero(second_par)) {
        return 0;
    } else {
        *x1 = - third_par / second_par;
        if (CompareDoublesWZero(*x1)) {
            *x1 = 0.;
        }
        return 1;
    }
}

int SolveQuadraticEquation(double first_par, double second_par, double third_par, double* x1, double* x2) {
    assert(isfinite(first_par));
    assert(isfinite(second_par));
    assert(isfinite(third_par));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x2 != x1);

    if (first_par == 0) {
        double root = 0.;
        switch (SolveLinearEquation(second_par, third_par, x1)) {
            case -1 :
                return -1;
                break;
            case 0 :
                return 0;
                break;
            case 1 :
                return 1;
                break;
            default:
                return -2;
        }
    }

    double discriminant = 0;
    discriminant = second_par * second_par - 4 * first_par * third_par;

    assert(isfinite(discriminant));

    double sqrt_of_discriminant = 0.;
    if (CompareDoublesWZero(discriminant)) {   
        assert(!CompareDoublesWZero(first_par));

        *x1 = (-second_par / (2 * first_par));
        if (CompareDoublesWZero(*x1)) {
            *x1 = 0.;
        }
        return 1;
    } else if (discriminant < -DBL_EPSILON) {
        return -1;
    } else {
        sqrt_of_discriminant = sqrt(discriminant);
        
        assert(isfinite(sqrt_of_discriminant));
        assert(!CompareDoublesWZero(first_par));

        *x1 = (-second_par - sqrt_of_discriminant) / (2 * first_par);
        *x2 = (-second_par + sqrt_of_discriminant) / (2 * first_par);

        if (CompareDoublesWZero(*x1)) {
            *x1 = 0.;
        }
        if (CompareDoublesWZero(*x2)) {
            *x2 = 0.;
        } 
        return 2;
    }
}

int main() {
    double first_par = 0;
    double second_par = 0;
    double third_par = 0;

    printf("Enter the first second and third parameters of the quadratic equation separated by a space:\n");
    scanf("%lf%lf%lf", &first_par, &second_par, &third_par);

    double x1 = 0;
    double x2 = 0;

    switch(SolveQuadraticEquation(first_par, second_par, third_par, &x1, &x2)) {
        case 2 :
            printf("your roots are equal :\n x1: %.10lf x2: %.10lf\n", x1, x2);
            break;
        case 1 :
            printf("your root is equal :\n x: %.10lf\n", x1);
            break;
        case 0 :
            printf("No roots\n");
            break;
        case -1 :
            printf("Any roots\n");
            break;
        default:
            printf("ERROR: Functon return error code\n");
    }

    return 0;
}