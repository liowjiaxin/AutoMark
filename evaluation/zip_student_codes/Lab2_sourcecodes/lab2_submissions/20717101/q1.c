#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, *array, index1, index2, valid = 0;

    // Step 1: Prompt user to enter the size of the array
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Invalid input. The size of the array must be at least 5.\n");
        }
    } while (N < 5);

    // Step 2: Dynamically allocate memory for the array
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Step 3: Prompt user to enter each element of the array
    printf("Enter %d elements for the array:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &array[i]);
    }

    // Step 4: Prompt user for two valid indices
    do {
        printf("Enter two indices (0 <= index1, index2 < %d):\n", N);
        printf("Index 1: ");
        scanf("%d", &index1);
        printf("Index 2: ");
        scanf("%d", &index2);
        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            valid = 1;
        } else {
            printf("Invalid indices. Please try again.\n");
        }
    } while (!valid);

    // Step 5: Compute the sum using pointers
    int sum = *(array + index1) + *(array + index2);

    // Step 6: Print the sum
    printf("The sum of elements at indices %d and %d is: %d\n", index1, index2, sum);

    // Free dynamically allocated memory
    free(array);

    return 0;
}
