#include <stdio.h>
#include <stdlib.h> // To allocate the dynamic memory

int main() {
    int N;   // Size of the array
    int *array;   // Pointer to hold the dynamically allocated array
    int index1;
    int index2; // Indices of the elements to sum

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);

    // Validate that N is at least 5
    while (N < 5) {
        printf("Error: Size of the array must be at least 5.\n");
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
    }

    // Dynamically allocate memory for the array
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {  // Check if memory allocation is good
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Prompt the user to enter each elements of the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array + i)); // Use pointer arithmetic to store the elements
    }

    // Prompt the user to enter the two indices
    printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
    scanf("%d %d", &index1, &index2);

    // Validate the indices
    while (index1 < 0 || index2 < 0 || index1 >= N || index2 >= N) {
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
    }

    // Calculate the sum using pointers
    int sum = *(array + index1) + *(array + index2);

    // Print the result
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // Free the allocated memory
    free(array);

    return 0;
}