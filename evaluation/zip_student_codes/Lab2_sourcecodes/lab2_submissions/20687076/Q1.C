QUESTION 1)

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, index1, index2, sum;
    int *array;

    // Step 1: Get the size of the array and validate
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);
    while (N < 5) {
        printf("Size must be at least 5. Try again: ");
        scanf("%d", &N);
    }

    // Step 2: Allocate memory for the array
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Step 3: Input array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    // Step 4: Get the indices and validate
    printf("Enter two indices (0 <= index < %d): ", N);
    scanf("%d %d", &index1, &index2);
    while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
        printf("Invalid indices. Try again: ");
        scanf("%d %d", &index1, &index2);
    }

    // Step 5: Calculate the sum
    sum = array[index1] + array[index2];

    // Step 6: Print the result
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // Free the allocated memory
    free(array);

    return 0;
}
