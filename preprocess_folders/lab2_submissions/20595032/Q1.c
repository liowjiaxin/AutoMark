#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    // Prompt for array size
    do {
        printf("Enter array size (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("The minimum number of arrays is 5.\n");
        }
    } while (N < 5);

    // Allocate memory
    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Prompt to enter array elements
    printf("Enter %d elements for the array (starting with index 0):\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element at index %d: ", i); // Start with 0
        scanf("%d", &arr[i]);
    }

    // Prompt to enter two indices
    int i1, i2;
    do {
        printf("Enter first index (0 to %d): ", N - 1);
        scanf("%d", &i1);
        if (i1 < 0 || i1 >= N) {
            printf("Invalid index, please enter a value between 0 and %d.\n", N - 1);
        }
    } while (i1 < 0 || i1 >= N);

    do {
        printf("Enter second index (0 to %d): ", N - 1);
        scanf("%d", &i2);
        if (i2 < 0 || i2 >= N) {
            printf("Invalid index, please enter a value between 0 and %d.\n", N - 1);
        }
    } while (i2 < 0 || i2 >= N);

    // Calculate the sum of the two elements
    int sum = arr[i1] + arr[i2];

    // Print the result
    printf("The sum of the elements at indices %d and %d is: %d\n", i1, i2, sum);

    // Free allocated memory
    free(arr);

    return 0;
}
