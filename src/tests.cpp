#include "quadratic_equation.h"

const int SIZE_ARRAY_TEST = 5;

struct TestCaseLinear {
    double first;
    double second;
    double root;
    int return_roots;
};

struct TestCaseQuadratic {
    double first;
    double second;
    double third;
    double root_first;
    double root_second;
    int return_roots;
};

void TestIsZero(double num[SIZE_ARRAY_TEST], bool correct_answer) {
    for (int i = 0; i < SIZE_ARRAY_TEST; i++) {
        if (!(correct_answer == IsZero(num[i]))) {
            printf("[INCORRECT] IsZero(%lf) returned %d; expected %d.\n",
                    num[i], IsZero(num[i]), correct_answer);
        } else {
            printf("[OK] IsZero(%lf) returned %d; expected %d.\n",
                    num[i], IsZero(num[i]), correct_answer);
        }
    }
}

void TestSolveLinearEquation(TestCaseLinear input[SIZE_ARRAY_TEST]) {
    double x;
    x = 0;
    for (int i = 0; i < SIZE_ARRAY_TEST; i++) {
        int return_value = SolveLinearEquation(input[i].first, input[i].second, &x);
        if (!(input[i].return_roots == return_value)) {
            printf("[INCORRECT] SolveLinearEquation(%lf %lf x) returned %d; expected %d.\n",
                    input[i].first, input[i].second, return_value, input[i].return_roots);
        } else {
            printf("[OK] SolveLinearEquation(%lf %lf x) returned %d; expected %d.\n",
                    input[i].first, input[i].second, return_value, input[i].return_roots);
        }
        if (x != input[i].root) {
            printf("[INCORRECT] Answer by SolveLinearEquation: %lf ; expected %lf.",
                    x, input[i].root);
        } else {
            printf("[OK] Answer by SolveLinearEquation: %lf ; expected %lf.",
                    x, input[i].root);
        }
        x = 0;
    }
}

void TestSolveQuadraticEquation(TestCaseQuadratic input[SIZE_ARRAY_TEST]) {
    double x1;
    double x2;
    x1 = 0;
    x2 = 0;
    for (int i = 0; i < SIZE_ARRAY_TEST; i++) {
        int return_value = SolveQuadraticEquation(input[i].first, input[i].second, input[i].third, &x1, &x2);
        if (!(input[i].return_roots == return_value)) {
            printf("[INCORRECT] SolveQuadraticEquation(%lf %lf %lf x1, x2) returned %d; expected %d.\n", 
                    input[i].first, input[i].second, input[i].third, return_value, input[i].return_roots);
        } else {
            printf("[OK] SolveQuadraticEquation(%lf %lf %lf x1, x2) returned %d; expected %d.\n", 
                    input[i].first, input[i].second, input[i].third, return_value, input[i].return_roots);
        }
        if (x1 != input[i].root_first && x2 != input[i].root_second) {
            printf("[INCORRECT] Answer by SolveQuadraticEquation: %lf %lf; expected %lf %lf.\n",
                    x1, x2, input[i].root_first, input[i].root_second);
        } else {
            printf("[OK] Answer by SolveQuadraticEquation: %lf %lf; expected %lf %lf.\n",
                    x1, x2, input[i].root_first, input[i].root_second);
        }
        x1 = 0;
        x2 = 0;
    }
}

int main() {
    double test_is_zero_true[SIZE_ARRAY_TEST] = {2.0e-017, 0.0f, -0.0f, 1.0e-016, 1.0e-020};
    double test_is_zero_false[SIZE_ARRAY_TEST] = {0.19f, -1.0f, -0.1f, -5, 5};
    TestCaseLinear test_solve_linear_equation[SIZE_ARRAY_TEST] = {{1, 0, 0, 1},
                                                                                  {-1, 0, 0, 1},
                                                                                  {20, 5, -0.25f, 1},
                                                                                  {0, 0, 0, ANY_ROOTS},
                                                                                  {0, 1, 0, 0}};
    TestCaseQuadratic test_solve_quadratic_equation[SIZE_ARRAY_TEST] = {{1, 1, 1, 0, 0, 0},
                                                                                         {1, 1, 0, -1.0f, 0.0f, 2},
                                                                                         {2, 5, 6, 0, 0, 0},
                                                                                         {0, 0, 0, 0, 0, ANY_ROOTS},
                                                                                         {1, -1, 0, 0.0f, 1.0f, 2}};

    TestIsZero(test_is_zero_false, false);
    TestIsZero(test_is_zero_true, true);

    TestSolveLinearEquation(test_solve_linear_equation);

    TestSolveQuadraticEquation(test_solve_quadratic_equation);
    return 0;
}