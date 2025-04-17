#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;   // Pointer to assign array size dynamically
    int size = 0;        // Size of array
    int index1, index2;  // Index for the target elements

    // User inputs the size of array and validate N ≥ 5
    do {
        printf("Enter the size of the array (N ≥ 5): ");
        scanf("%d", &size);
        if (size < 5) {
            printf("Invalid input. The size must be at least 5.\n");
        }
    } while (size < 5);

    // Using malloc to assign size of array dynamically
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    // User inputs elements inside the array
    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    // User inputs 2 index and sums up the elements of the 2 chosen index, validate invalid index
    do {
        printf("Enter the first index (0 ≤ index < %d): ", size);
        scanf("%d", &index1);

        printf("Enter the second index (0 ≤ index < %d): ", size);
        scanf("%d", &index2);

        if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {
            printf("Invalid indices. Please try again.\n");
        }
    } while (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size);

    // Calculation of the sum of the two elements chosen
    int sum = *(arr + index1) + *(arr + index2);

    // Print the sum
    printf("The sum of elements at indices %d and %d is: %d\n", index1, index2, sum);

    return 0;
}
