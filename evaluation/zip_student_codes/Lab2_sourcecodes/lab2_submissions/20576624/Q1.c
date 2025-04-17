#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    // 1) Input N, check if N>=5
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Invalid size. Please enter a number greater than or equal to 5.\n");
        }
    } while (N < 5);

    // 2) Allocate memory
    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // 3) Enter values
    printf("Enter %d elements of the array:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", arr + i);  // Using pointers 
    }

    int index1, index2;

    // 4) Choose and validate indices
    do {
        printf("Enter the first index (0 ≤ index < %d): ", N);
        scanf("%d", &index1);
        if (index1 < 0 || index1 >= N) {
            printf("Invalid index. Please enter an index between 0 and %d.\n", N - 1);
        }
    } while (index1 < 0 || index1 >= N);

    do {
        printf("Enter the second index (0 ≤ index < %d): ", N);
        scanf("%d", &index2);
        if (index2 < 0 || index2 >= N) {
            printf("Invalid index. Please enter an index between 0 and %d.\n", N - 1);
        }
    } while (index2 < 0 || index2 >= N);

    // 5) Use a pointer-based approach to find the sum of the values of the two array elements.
    int sum = *(arr + index1) + *(arr + index2);

    // 6) Print the output for the sum.
    printf("The sum of the elements at indices %d and %d is %d.\n", index1, index2, sum);

    // Free the allocated memory.
    free(arr);

    return 0;
}
