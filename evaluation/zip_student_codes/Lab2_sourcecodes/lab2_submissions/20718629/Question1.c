#include <stdio.h>
#define MAX_SIZE 200

int main() {
    int n;
    int array[MAX_SIZE]; 
    int num1, num2;

    // Make sure the size of the array (N >= 5)
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &n);

        if (n < 5) {
            printf("Error: Size of the array must be at least 5. Please try again.\n");
        }
    } while (n < 5);

    // Prompt the user to enter the element of the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    // Prompt the user to enter the two indices 
    do {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", n);
        scanf("%d %d", &num1, &num2);

        if (num1 < 0 || num1 >= n || num2 < 0 || num2 >= n) {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    } while (num1 < 0 || num1 >= n || num2 < 0 || num2 >= n);

    // Calculate the sum using pointer arithmetic
    int sum = *(array + num1) + *(array + num2);

    // Print the result 
    printf("The sum of the values at indices %d and %d is: %d\n", num1, num2, sum);

    return 0;
}