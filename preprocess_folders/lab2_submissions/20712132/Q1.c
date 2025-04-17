#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL; // pointer for the array
    int N; // size of the array
    int index1, index2; // indices for the two elements to be added
    int sum;

    // ask the user to enter the size of the array
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Invalid size. Please enter a value greater than or equal to 5.\n");
        }
    } while (N < 5);

    // allocate memory for the array
    arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // ask the user to enter elements of the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (arr + i)); // Use pointer arithmetic to access the array
    }

    // ask the user to enter two indices and validate
    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d):\n", N);
        printf("Index 1: ");
        scanf("%d", &index1);
        printf("Index 2: ");
        scanf("%d", &index2);

        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            break;
        } else {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n", N);
        }
    }

    // 5) Use pointer-based approach to compute the sum
    sum = *(arr + index1) + *(arr + index2);

    // 6) Print the sum
    printf("The sum of the elements at indices %d and %d is: %d\n", index1, index2, sum);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
