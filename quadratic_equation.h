#include <stdio.h>
#include <math.h>

const int ANY_ROOTS = -1;

bool IsZero(double num);
int SolveLinearEquation(double first_par, double second_par, double* x);
int SolveQuadraticEquation(double first_par, double second_par, double third_par, double* x1, double* x2);