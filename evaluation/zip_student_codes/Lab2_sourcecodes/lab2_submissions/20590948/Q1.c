#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL; // Dynamic memory handle
    int N;           // Specify the number of elements in the array
    int index1, index2; // Input the indices of the elements to calculate the sum


    // Step 1: Prompt user to enter the array size and ensure it is valid
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Invalid size! Please enter a value greater than or equal to 5.\n");
        }
    } while (N < 5);

    // Step 2: Allocate memory for the array dynamically 
    arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Terminate the program if memory allocation fails 
    }

    // Step 3: Request the user to input elements of the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (arr + i)); // Access elements using pointer arithmetic
    }

    // Step 4: Ask the user for indices and ensure they are valid 
    do {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);

        // Validate indices
        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    // Step 5:  Calculate the sum using pointers to access elements
    int sum = *(arr + index1) + *(arr + index2);

    // Step 6: Print the result
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // Free the allocated memory block
    free(arr);

    return 0;
}
