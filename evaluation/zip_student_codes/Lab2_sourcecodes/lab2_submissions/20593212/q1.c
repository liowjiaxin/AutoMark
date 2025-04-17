#include <stdio.h>
#include <stdlib.h>

// Function to get valid indices from the user
void getValidIndices(int *index1, int *index2, int n) {
    // Loop to ensure the first index is valid
    do {
        printf("Enter the first index (0 <= index1 < %d): ", n);
        scanf("%d", index1);
        if (*index1 < 0 || *index1 >= n) {
            printf("Invalid index1! Please enter a valid index.\n");
        }
    } while (*index1 < 0 || *index1 >= n);

    // Loop to ensure the second index is valid
    do {
        printf("Enter the second index (0 <= index2 < %d): ", n);
        scanf("%d", index2);
        if (*index2 < 0 || *index2 >= n) {
            printf("Invalid index2! Please enter a valid index.\n");
        }
    } while (*index2 < 0 || *index2 >= n);
}

int main() {
    int N;

    // Step 1: Prompt user for array size and validate N >= 5
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Invalid size! The size must be at least 5.\n");
        }
    } while (N < 5);

    // Step 2: Dynamically allocate memory for the array
    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit if memory allocation fails
    }

    // Step 3: Prompt user to enter array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    int index1, index2;

    // Step 4: Prompt user to enter the two indices
    getValidIndices(&index1, &index2, N);

    // Step 5: Use pointers to calculate the sum of the two target elements
    int sum = *(arr + index1) + *(arr + index2); // Pointer-based access

    // Step 6: Print the sum of the two elements
    printf("The sum of the elements at index %d and %d is: %d\n", index1, index2, sum);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
