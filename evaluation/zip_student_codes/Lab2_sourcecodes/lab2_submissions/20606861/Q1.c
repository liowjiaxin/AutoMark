#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main() {
    int N;
    int *array;
    int *ptr;
    int index1, index2;

    // Ask for the array size (must be at least 5)
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Error: The size of the array must be at least 5. Please try again.\n");
        }
    } while (N < 5);

    // Allocate memory for the array
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1; // Exit if memory allocation fails
    }

    // Input elements into the array
    printf("Enter the array elements:\n");
    ptr = array; // Point to the start of the array
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", ptr); // Store input directly using pointer
        ptr++; // Move pointer to the next element
    }

    // Input the indices and validate them
    do {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
        if (index1 < 0 || index2 < 0 || index1 >= N || index2 >= N) {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    } while (index1 < 0 || index2 < 0 || index1 >= N || index2 >= N);

    // Calculate the sum using pointers
    int sum = *(array + index1) + *(array + index2);

    // Output the result
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // Free the allocated memory
    free(array);

    return 0;
}
