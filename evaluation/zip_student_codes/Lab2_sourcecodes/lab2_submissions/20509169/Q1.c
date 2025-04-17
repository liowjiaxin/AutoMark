#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Size of array must be at least 5. Please try again.\n");
        }
    } while (N < 5);

    int *arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    printf("Enter %d integers for the array:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int index1, index2;
    do {
        printf("Enter the first index (0 to %d): ", N-1);
        scanf("%d", &index1);
        printf("Enter the second index (0 to %d): ", N-1);
        scanf("%d", &index2);
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    int sum = *(arr + index1) + *(arr + index2);

    printf("The sum of elements at index %d and %d is: %d\n", index1, index2, sum);

    free(arr);
    return 0;
}

