#include "custom_lib.h"
#include <cmath> // for pow and sqrt functions
using namespace std;

// Function definitions for arithmetic operations

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        return 0; // Returning 0 as a default value, could also throw an exception if preferred
    }
    return a / b;
}

double power(double base, double exponent) {
    return std::pow(base, exponent);
}

double square_root(double x) {
    if (x < 0) {
        return 0; // Returning 0 as a default value, could also throw an exception if preferred
    }
    return std::sqrt(x);
}