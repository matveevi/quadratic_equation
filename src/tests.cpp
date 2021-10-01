#include "quadratic_equation.h"

struct CoefficentsForLinear {
    double first;
    double second;
    double root;
    int return_roots;
};

struct CoefficentsForQuadratic {
    double first;
    double second;
    double third;
    double root_first;
    double root_second;
    int return_roots;
};

bool TestIsZero(double num[3], bool check_veriable) {
    for (int i = 0; i < 3; i++) {
        if (!(check_veriable == IsZero(num[i]))) {
            return false;
        }
    }

    return true;
}

bool TestSolveLinearEquation(CoefficentsForLinear input[5]) {
    double x;
    x = 0;
    for (int i = 0; i < 5; i++) {
        if (!(input[i].return_roots == SolveLinearEquation(input[i].first, input[i].second, &x)) && x != input[i].root) {
            return false;
        }
        x = 0;
    }

    return true;
}

bool TestSolveQuadraticEquation(CoefficentsForQuadratic input[5]) {
    double x1;
    double x2;
    x1 = 0;
    x2 = 0;
    for (int i = 0; i < 5; i++) {
        if (!(input[i].return_roots == SolveQuadraticEquation(input[i].first, input[i].second, input[i].third, &x1, &x2))) {
            return false;
        }
        if (x1 != input[i].root_first && x2 != input[i].root_second) {
            return false;
        }
        x1 = 0;
        x2 = 0;
    }

    return true;
}

int main() {
    double test_is_zero_true[3] = {2.0e-017, 0.0f, -0.0f};
    double test_is_zero_false[3] = {0.19f, -1.0f, -0.1f};
    CoefficentsForLinear test_solve_linear_equation[5] = {{1, 0, 0, 1}, {-1, 0, 0, 1}, {20, 5, -0.25f, 1}, {0, 0, 0, ANY_ROOTS}, {0, 1, 0, 0}};
    CoefficentsForQuadratic test_solve_quadratic_equation[5] = {{1, 1, 1, 0, 0, 0}, {1, 1, 0, -1.0f, 0.0f, 2}, {2, 5, 6, 0, 0, 0}, {0, 0, 0, 0, 0, ANY_ROOTS}, {1, -1, 0, 0.0f, 1.0f, 2}};

    for (int i = 0; i < 5; i++) {
        if (!TestIsZero(test_is_zero_false, false) || !TestIsZero(test_is_zero_true, true)) {
            printf("Error in function IsZero\n");
            return 1;
        }
        if (!TestSolveLinearEquation(test_solve_linear_equation)) {
            printf("Error in function SolveLinearEquation\n");
            return 1;
        }
        if (!TestSolveQuadraticEquation(test_solve_quadratic_equation)) {
            printf("Error in function SolveQuadraticEquation\n");
            return 1;
        }
    }

    printf("Everything is good\n");

    return 0;
}