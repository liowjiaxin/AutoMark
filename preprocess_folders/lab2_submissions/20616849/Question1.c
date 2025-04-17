#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, *array, index1, index2, sum;

    //User input
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Error: N must be greater or equal to 5. Please try again.\n");
        }
    } while (N < 5);

    //Allocate memory to array
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //Input elements to array
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", (array + i));
    }

    //User input
    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);

        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            break; // Valid indices
        } else {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    }

    //Calculating the sum
    sum = *(array + index1) + *(array + index2);

    //Print the sum
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    //Release allocated memory
    free(array);

    return 0;
}