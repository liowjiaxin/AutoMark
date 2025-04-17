//Libraries :
#include <stdio.h>
#include <stdlib.h>

// Function to validate user input for array indices
int validateIndex(int index, int size) {
    return index >= 0 && index < size;
}

int main() {
    int arraySize, index1, index2;
    
    // Prompt user to enter the size of the array
    printf("Enter the size of the array (minimum 5): ");
    scanf("%d", &arraySize);

    // Validate size
    if (arraySize < 5) {
        printf("Error: Array size must be at least 5.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int *array = (int *)malloc(arraySize * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d elements for the array:\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    // Input and validate indices
    do {
        printf("Enter the first index (0 to %d): ", arraySize - 1);
        scanf("%d", &index1);
    } while (!validateIndex(index1, arraySize));

    do {
        printf("Enter the second index (0 to %d): ", arraySize - 1);
        scanf("%d", &index2);
    } while (!validateIndex(index2, arraySize));

    // Calculate the sum using pointers
    int sum = *(array + index1) + *(array + index2);
    printf("The sum of elements at indices %d and %d is: %d\n", index1, index2, sum);

    // Free allocated memory
    free(array);
    return EXIT_SUCCESS;
}
