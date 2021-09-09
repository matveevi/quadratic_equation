#include "quadratic_equation.h"

int main() {
    double first_par = 0;
    double second_par = 0;
    double third_par = 0;

    printf("Enter the first second and third parameters of the quadratic equation separated by a space:\n");
    scanf("%lf%lf%lf", &first_par, &second_par, &third_par);

    if (first_par == 0) {
        double root = 0.;
        switch (LinearHomogeneousEquation(second_par, third_par)) {
            case 2 :
                printf("Any roots\n");
                break;
            case 0 :
                printf("No roots\n");
                break;
            case 1 :
                root = - third_par / second_par;
                if (root < EXP && root > -EXP) {
                    root = 0.;
                }
                printf("!your root is equal :\n x: %.10lf\n", root);
                break;
        }

        return 0;
    }

    double x1 = 0;
    double x2 = 0;

    switch(Solve(first_par, second_par, third_par, &x1, &x2)) {
        case 2 :
            printf("your roots are equal :\n x1: %.10lf x2: %.10lf\n", x1, x2);
            break;
        case 1 :
            printf("your root is equal :\n x: %.10lf\n", x1);
            break;
        case 0 :
            printf("No roots\n");
            break;
    }

    return 0;
}