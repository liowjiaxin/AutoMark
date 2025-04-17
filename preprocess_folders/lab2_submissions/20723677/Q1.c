#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    // Prompt user for the size of the array
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Invalid size. N must be at least 5.\n");
        }
    } while (N < 5);

    // Dymically allocate memory for the array using pointers
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Prompt user to enter each element of the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array + i));
    }

    int index1, index2;

    // Prompt user for the two indices and validate
    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < 6): ");
        scanf("%d %d", &index1, &index2);

        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            break;
        } else {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n"); // Prompt user for input again until the indices entered are valid
        }
    }

    // Use pointers to find the sum of the values at the two indices
    int sum = *(array + index1) + *(array + index2);

    // Print the sum
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // Free dynamically allocated memory
    free(array);

    return 0;
    }


