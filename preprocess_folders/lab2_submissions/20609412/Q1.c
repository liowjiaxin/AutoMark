#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;           // Declare a pointer for dynamically allocated array
    int N, index1, index2;

    // Get the size of the array (>= 5)
    do {
        printf("Enter the size of the array elements (must be >= 5): ");
        scanf("%d", &N);
    } while (N < 5);

    // Allocate memory dynamically using malloc()
    arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit if malloc fails
    }

    // Get the array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Get the indices of two elements
    printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
    scanf("%d%d", &index1, &index2);

    // Validate indices
    while (index1 < 0 || index2 < 0 || index1 >= N || index2 >= N) {
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d%d", &index1, &index2);
    }

    // Check for duplicates and replace them with -99
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] == arr[j]) {
                arr[j] = -99; // Replace duplicate with -99
            }
        }
    }

    // Print the modified array
    printf("Modified array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
