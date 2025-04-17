#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;
    int a = 0;
    int b = 0;
    int sum = 0;
    int* arr = NULL;

    printf("Enter the size of the array (must be >= 5): ");
    scanf("%d", &n);
    while (n < 5) {
        printf("Invalid size. Size must be >= 5.\n");
        printf("Enter the size of the array (must be >= 5): ");
        scanf("%d", &n);
    }

    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", (arr + i));
    }

    printf("Enter first value (0 to %d): ", n - 1);
    scanf("%d", &a);
    printf("Enter second value (0 to %d): ", n - 1);
    scanf("%d", &b);

    while (a < 0 || a >= n || b < 0 || b >= n) {
        printf("Invalid values! Please enter values between 0 and %d.\n", n - 1);
        printf("Enter first value (0 to %d): ", n - 1);
        scanf("%d", &a);
        printf("Enter second value (0 to %d): ", n - 1);
        scanf("%d", &b);
    }

    sum = *(arr + a) + *(arr + b);

    printf("Sum of elements at values %d and %d is: %d\n", a, b, sum);

    free(arr);

    return 0;
}