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
#include <stdio.h>

/* 
 * Calculate sine using Taylor series approximation
 * x: input value in radians
 * n: number of terms in the series
 * Returns: approximation of sin(x)
 */

double taylor_sine(double x, int n) {
    double sine_value = 0.0;
    double term = x;     // First term 
    int sign = 1;        // Alternates between + and -

    for (int k = 1; k <= n; k++) {
        sine_value += sign * term;
        term = term * x * x / ((2 * k) * (2 * k + 1));
        sign = -sign; // Numerical value
    }

    return sine_value;
}
 // TODO: Implement the Taylor series approximation for sine
    // Hint: The series is: x - x^3/3! + x^5/5! - x^7/7! + ...
    // Use a loop to calculate n terms of the series
    
int main() {
    double x;
    int n;

    printf("Enter x (radians): ");
    scanf("%lf", &x);

    printf("Enter number of terms n: ");
    scanf("%d", &n);

    double result = taylor_sine(x, n);
    printf("sin(%f) = %f using %d terms\n", x, result, n);

    return 0;
}