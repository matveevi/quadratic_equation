#include <stdio.h>
#include <ctype.h>
#include "quadratic_equation.h"

/**
 * @brief Flush stdin
 * @param first_par pointer to the first parameter
 * @param second_par pointer to the second parameter
 * @param third_par pointer to the third parameter
 * @version 1.0
 */

void FlushInput() {
    while(getchar() != '\n') { 
        continue;
    }
}

/**
 * @brief Function compares a real number to zero
 * @param first_par pointer to the first parameter
 * @param second_par pointer to the second parameter
 * @param third_par pointer to the third parameter
 * @version 1.0
 */

void InputParameters(double* first_par, double* second_par, double* third_par) {
    printf("Enter the first second and third parameters of the quadratic equation separated by a space:\n");

    int correct_params = 0;

    while ((correct_params = scanf("%lf%lf%lf", first_par, second_par, third_par)) != 3){
        printf("INCORECT INPUT. TRY AGAIN\n");

        FlushInput();
    }
}

int main() {
    double first_par = 0;
    double second_par = 0;
    double third_par = 0;

    InputParameters(&first_par, &second_par, &third_par);

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
        case ANY_ROOTS :
            printf("Any roots\n");
            break;
        default:
            printf("ERROR\n");
            return -1;
    }

    return 0;
}