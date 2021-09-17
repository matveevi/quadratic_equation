#include <stdio.h>
#include <ctype.h>
#include "quadratic_equation.h"

int main() {
    double first_par = 0;
    double second_par = 0;
    double third_par = 0;

    printf("Enter the first second and third parameters of the quadratic equation separated by a space:\n");

    int result_scanf = 0;

    do {
        result_scanf = scanf("%lf%lf%lf", &first_par, &second_par, &third_par);

        if (result_scanf == 0) {
            printf("INCORECT INPUT. TRY AGAIN\n");
        }

        while(getchar() != '\n') {
            continue;
        }

    } while (result_scanf != 3);

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