#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int *array;
    int index1, index2;

    // Ask the user to enter the size N of the array. Check if N >= 5
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Error: N must be at least 5. Please try again.\n");
        }
    } while (N < 5);

    // Dynamically allocate memory for the array using pointers
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Prompt the user to enter each element of the array one by one
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    // Prompt the user to enter the two indices (positions) of the array elements of their choice
    do {
        printf("Enter the indices of the two elements ex: 3 4 (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    // Use a pointer-based approach to find the sum of the values of the two array elements
    int sum = *(array + index1) + *(array + index2);

    //  Print the output for the sum
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // Free the dynamically allocated memory
    free(array);

    return 0;
}
