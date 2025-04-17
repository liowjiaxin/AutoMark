#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    int *array;
    int index1, index2;

    // Do while loop for validation
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("N must be bigger than 5. ");
        }
    } while (N < 5);

    // Allocation memory using pointers into the array
    array = (int *)malloc(N *sizeof(int));
    if (array == NULL) { // Prints error if memory allocation fails
        printf("Memory allocation failed. \n");
        return 1;
    }

    // Assigning values to the element.
    printf("Enter %d of elements in the array. \n", N);
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i );
        scanf("%d", (array + i));
    }

    do {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);

        if (index1 < 0 || index1 > N || index2 < 0 || index2 > N) {
            printf(" Error: Indices must be within  the range of the array elements. Please try again. ");
        } else {
            break;
        }
    } while (1);

    // Using pointers to sum
    int sum = *(array + index1) + *(array + index2);
    printf("The sum of the values at indices %d and %d is: %d \n", index1, index2, sum);

    free(array);

    return 0;
}