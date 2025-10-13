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
#include <math.h>

double fact(int num) {
    double result = 1.0;
    for (int i = 0; i <= num; i++) {
        result *= i;
    }
}

/* 
 * Calculate sine using Taylor series approximation
 * x: input value in radians
 * n: number of terms in the series
 * Returns: approximation of sin(x)
 */
double taylor_sine(double x, int n) {
   double result = 0.0;

    for (int i = 0; i < n; i++){
        int power = 2 * i + 1;
        double term = 1.0;

        for (int j = 0; j < power; j++) {
            term *= x;
        }

        if (i % 2 == 0) {
            result += term / fact(power);
        }
        else {
            result -= term / fact(power);
        }
    }
    
    return result; // placeholder - replace with your implementation
}
 // TODO: Implement the Taylor series approximation for sine
    // Hint: The series is: x - x^3/3! + x^5/5! - x^7/7! + ...
    // Use a loop to calculate n terms of the series