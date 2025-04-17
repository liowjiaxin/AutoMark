#include <stdio.h>
#include <stdlib.h>

// Function to validate if an index is within bounds
int validate_index(int index, int size) {
    return index >= 0 && index < size;
}

int main() {
    int N, index1, index2;

    // Step 1: Prompt the user to input the size of the array
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);

    // Validate that the size is at least 5
    while (N < 5) {
        printf("Error: The size must be at least 5. Please try again: ");
        scanf("%d", &N);
    }

    // Step 2: Dynamically allocate memory for the array
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed. Exiting the program.\n");
        return 1;
    }

    // Step 3: Prompt the user to input the array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array + i));
    }

    // Step 4: Prompt the user to input two indices and validate them
    printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
    scanf("%d %d", &index1, &index2);

    // Validate both indices
    while (!validate_index(index1, N) || !validate_index(index2, N)) {
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
    }

    // Step 5: Calculate the sum of the elements at the two indices
    int sum = *(array + index1) + *(array + index2);

    // Step 6: Print the sum
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // Step 7: Free dynamically allocated memory
    free(array);

    return 0;
}
