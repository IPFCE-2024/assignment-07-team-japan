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
    double two_pi = 6.283185307179586; //modulo 2pi to increase precision
    while (x > two_pi) x -= two_pi;
    while (x < -two_pi) x += two_pi;

    double sine_value = 0.0;
    double term = x;
    int sign = 1;

    for (int k = 1; k <= n; k++) {
        sine_value += sign * term;
        term = term * x * x / ((2 * k) * (2 * k + 1));
        sign = -sign;
    }

    return sine_value;
}
 // TODO: Implement the Taylor series approximation for sine
    // Hint: The series is: x - x^3/3! + x^5/5! - x^7/7! + ...
    // Use a loop to calculate n terms of the series