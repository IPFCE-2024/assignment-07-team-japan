#include <stdio.h>
#include "taylor_sine.h"
#include <math.h>

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
/*
At first the program gave some questionable answers for higher values, but after implementing a calculation
by modulo of 2pi, it can now approximate the value of sin(x) pretty well with n=16. With lower values of n, we dont
quite achieve a result with enough precision for the result to have any real value. Like always with taylor approximation
can too high a value of n also impact the approximation negatively. 
*/