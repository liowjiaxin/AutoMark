#include <stdio.h>

int main() {
    // Initialize all of the variables
    int num1 = 0, num2 = 0, num3 = 0;
    int sum = 0, prod = 0, min = 0, max = 0;
    float avg = 0.0;

    // Prompt user for input
    printf("Enter 3 space-separated integers (eg. 10 20 30): ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Calculate sum
    sum = num1 + num2 + num3;

    // Calculate average
    avg = (float) sum / 3;

    // Calculate product
    prod = num1 * num2 * num3;

    // Calculate min
    min = num1;
    if (num2 < min) {
        min = num2;
    } 
    if (num3 < min) {
        min = num3;
    }

    // Calculate max
    max = num1;
    if (num2 > max) {
        max = num2;
    }
    if (num3 > max) {
        max = num3;
    }

    // Output calculations (mul)
    printf("Sum: %d\n"
           "Average: %.2f\n"
           "Product: %d\n"
           "Smallest: %d\n"
           "Largest: %d", sum, avg, prod, min, max);

    return 0;
}