/**
 * Implementation of functions used in solve quadratic equation
 * 
 * @author Ilya Matveev
 * @file quadratic_equation.h
 * @date 2021-09-25
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <math.h>

const int ANY_ROOTS = -1;

/**
 * @brief Compares a real number to zero
 * 
 * @param num real number
 * @version 1.0
 * @return whether num is zero
 */

bool IsZero(double num);

/**
 * @brief Solve linear equation first_par * x + second_par = 0
 * 
 * @param first_par first parameter of the linear equation
 * @param second_par second parameter of the linear equation
 * @param x pointer to root of the linear equation
 * @version 1.0
 * @return number of roots
 */

int SolveLinearEquation(double first_par, double second_par, double* x);

/**
 * @brief Solve quadratic equation first_par * x^2 + second_par * x + third_par = 0
 * 
 * @param first_par first parameter of the quadratic equation
 * @param second_par second parameter of the quadratic equation
 * @param third_par third parameter of the quadratic equation
 * @param x1 pointer to the first root of the quadratic equation
 * @param x2 pointer to the second root of the quadratic equation
 * @version 1.0
 * @return number of roots
 */

int SolveQuadraticEquation(double first_par, double second_par, double third_par, double* x1, double* x2);