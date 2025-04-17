#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Memory library

int main() {
    int N; // Array
    int *arr; // Pointer 
    int index1, index2; // Variables to store the two indices
    int sum; // Variable to store the sum

    // Prompts the user to enter the size of the array
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);

        if (N < 5) {
            printf("Size must at least be 5. Please try again.\n");
        }
    } while (N < 5);

    // Memory for the array
    arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    // Prompts the user to enter the elements of the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (arr + i)); // Pointer arithmetic to store values
    }

    // Prompt the user to enter the indices
    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);

        // Validation
        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            break; // Exit loop if valid
        } else {
            printf("Indices must be within the range of the array elements. Please try again.\n");
        }
    }

    // Calculate the sum using pointer arithmetic
    sum = *(arr + index1) + *(arr + index2);

    // Display the sum
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // Free memory
    free(arr);

    return 0;
}
