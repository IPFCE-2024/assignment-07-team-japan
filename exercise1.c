/*
 * Exercise 1: Taylor Series Approximation for Sine Function
 * Assignment 7 - IPFCE 2025
 * 
 * Implement the taylor_sine function that calculates the sine of x
 * using Taylor series approximation with n terms.
 * 
 * Taylor series for sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 */

#include "taylor_sine.h"

double fact(int k) {
    double result = 1.0;
    for (int i = 2; i <= k; i++) {
        result *= i;
    }
    return result;
}

double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

/* 
 * Calculate sine using Taylor series approximation
 * x: input value in radians
 * n: number of terms in the series
 * Returns: approximation of sin(x)
 */

double taylor_sine(double x, int n) {
    double result = 0.0;
    double term;
    int sign = 1;

    for (int i = 0; i < n; i++) {
        int power = 2 * i + 1;              // 1, 3, 5, 7, ...
        term = sign * (pow(x, power) / factorial(power));
        result += term;
        sign *= -1;                         // alternate between + and -
    }

    return result;
}
 // TODO: Implement the Taylor series approximation for sine
    // Hint: The series is: x - x^3/3! + x^5/5! - x^7/7! + ...
    // Use a loop to calculate n terms of the series