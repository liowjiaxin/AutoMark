#include <stdio.h>
#include <stdlib.h>

int main() {
    int N; // The size of the array
    int *arr; // Pointer for the dynamically allocated array
    int *ptr1, *ptr2; // Pointers for the selected elements
    int index1, index2; // Indices chosen by the user
    int sum; // Sum of the two numbers at the chosen indices

    // Prompt the user to enter the size of the array (N) and ensure it's at least 5
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N); // read size of array
    while (N < 5) { // Creating condition
        printf("Invalid size! Enter a number 5 or more: ");
        scanf("%d", &N); // Continue prompt until valid input is given
    }

    // Allocate memory for the array
    arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) { // Creating condition
        printf("Memory allocation failed. Exiting...\n");
        return 1; // Exit the program if memory couldn't be allocated
    }

    // Prompt the user to enter each element of the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (arr + i)); // Store values using pointer arithmetic
    }

    // Prompt the user to enter two indices for the array elements
    printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
    scanf("%d %d", &index1, &index2); // Read indices in a single input 

    // Validate the indices are within range
    while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
    }

    // Set pointers to the chosen indices
    ptr1 = arr + index1; // Pointer to the first element
    ptr2 = arr + index2; // Pointer to the second element

    // Compute the sum using the pointers
    sum = *ptr1 + *ptr2;

    // Display the result
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // Free the allocated memory
    free(arr);

    return 0;
}


    
