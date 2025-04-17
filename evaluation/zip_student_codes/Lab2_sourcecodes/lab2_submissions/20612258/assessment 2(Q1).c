#include <stdio.h>
#include <stdlib.h> // Required for dynamic memory allocation

int main() {
    int N, *array = NULL, index1 = -1, index2 = -1, sum = 0;

    // Step 1: Prompt user for the size of the array
    printf("Enter the size of the array (N >= 5): ");
    while (1) {
        scanf("%d", &N);
        if (N >= 5) { // Valid input
            break;
        }
        printf("Error: N must be at least 5. Please try again: ");
    }

    // Step 2: Dynamically allocate memory for the array
    array = (int *)malloc(N * sizeof(int));
    if (!array) { // Check for allocation failure
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Step 3: Populate the array with user input
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]); // Accessing using array subscript notation
    }

    // Step 4: Prompt user to enter two valid indices
    printf("Enter the indices of two elements (0 <= index1, index2 < %d): ", N);
    while (1) {
        scanf("%d %d", &index1, &index2);

        // Validate indices
        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            break;
        }
        printf("Error: Indices must be within the range [0, %d). Please try again: ", N);
    }

    // Step 5: Compute the sum of the selected elements
    sum = array[index1] + array[index2]; // Accessing using array subscript notation

    // Step 6: Display the sum
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // Step 7: Free the allocated memory
    free(array);

    return 0;
}
