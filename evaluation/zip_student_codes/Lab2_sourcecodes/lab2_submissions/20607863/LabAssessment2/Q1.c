#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 0;
    int *array;
    int index1 = 0, index2 = 0;
    int sum = 0;

    // Prompt user for size of array
    while (1) {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &size);

        // Validate size >= 5
        if (size >= 5) {
            break;
        } else {
            puts("Size not in correct range. Try again.");
        }
    }

    // Allocate memory for the array
    array = malloc(size * sizeof(*array));

    // Prompt user for array elements
    puts("Enter the elements of the array:");
    for (size_t i=0; i<size; i++) {
        printf("Element %d: ", i);
        scanf("%d",array+i);
    }

    // Prompt user for indices
    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", size);
        scanf("%d %d", &index1, &index2);

        // Input validation
        if (0 <= index1 && index1 < size && 0 <= index2 && index2 < size) {
            break;
        } else {
            puts("Values not in correct range. Try again.");
        }
    }

    // Calculate and output sum
    sum = *(array+index1) + *(array+index2);
    printf("The sum of the integers in index %d and %d: %d", index1, index2, sum);

    free(array);

    return 0;
}