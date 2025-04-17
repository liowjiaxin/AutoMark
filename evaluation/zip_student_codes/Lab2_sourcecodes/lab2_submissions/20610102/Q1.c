#include <stdio.h>
#include <stdlib.h>

int main() {
    int N=0;

    // 1.Prompt user for array size and validate
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Invalid size. N must be at least 5.\n");
        }
    } while (N < 5);

    // 2.allocate memory for the array
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    // 3.Input array elements
    printf("Enter %d elements for the array:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array+i)); // Using pointer arithmetic
    }

    int index1, index2;

    // 4.Input indices and validate
    do {
        printf("Enter two indices (0 <= index1, index2 < %d):\n", N);
        printf("Index1: ");
        scanf("%d", &index1);
        printf("Index2: ");
        scanf("%d", &index2);

        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Invalid indices. Please try again.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    // 5.Calculate sum using pointers
    int sum = *(array + index1) + *(array + index2);

    // 6.Print the sum
    printf("The sum of elements at indices %d and %d is: %d\n", index1, index2, sum);

    // Free allocated memory
    free(array);

    return 0;
}
