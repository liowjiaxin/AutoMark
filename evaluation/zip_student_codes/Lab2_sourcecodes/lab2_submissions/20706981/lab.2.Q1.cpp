#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    // Step 1: Prompt the user for the size of the array and validate if N >= 5
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Error: Size must be at least 5. Please try again.\n");
        }
    } while (N < 5);

    // Step 2: Dynamically allocate memory for the array
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Step 3: Prompt the user to enter each element of the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    int index1, index2;

    // Step 4: Prompt the user for two indices and validate them
    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);

        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            break; // Both indices are valid
        } else {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    }

    // Step 5:  find the sum of the two array elements
    int sum = *(array + index1) + *(array + index2);

    // Step 6: Print 
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // Free the  memory
    free(array);

    return 0;
}
