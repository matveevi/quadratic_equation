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

    double discriminant = 0;
    discriminant = second_par * second_par - 4 * first_par * third_par;
    printf("discriminant: %.10lf\n", discriminant);

    double sqrt_of_discriminant = 0.;
    double x1 = 0;
    double x2 = 0;
    double x = 0;

    switch(NumberOfSolutions(discriminant)) {
        case 2 :
            sqrt_of_discriminant = sqrt(discriminant);
            
            x1 = (-second_par - sqrt_of_discriminant) / (2 * first_par);
            x2 = (-second_par + sqrt_of_discriminant) / (2 * first_par);

            if (x1 < EXP && x1 > -EXP) {
                x1 = 0.;
            }
            if (x2 < EXP && x2 > -EXP) {
                x2 = 0.;
            }

            printf("your roots are equal :\n x1: %.10lf x2: %.10lf\n", x1, x2);
            break;
        case 1 :
            x = (- second_par / (2 * first_par));
            if (x < EXP && x > -EXP) {
                x = 0.;
            }

            printf("your root is equal :\n x: %.10lf\n", x);
            break;
        case 0 :
            printf("No roots\n");
            break;
    }

    return 0;
}