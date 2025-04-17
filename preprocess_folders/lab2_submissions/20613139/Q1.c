#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, index1, index2;
    int *array;

    //Input and validate array size
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Invalid size. Please enter a value greater than or equal to 5.\n");
        }
    } while (N < 5);

    //Dynamically allocate memory for the array
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    //Input array elements
    printf("Enter %d elements for the array:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    //Input and validate indices
    do {
        printf("Enter two indices (0 <= index1, index2 < %d):\n", N);
        scanf("%d %d", &index1, &index2);
        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Invalid indices. Please enter valid indices.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    //Compute sum using pointers
    int sum = *(array + index1) + *(array + index2);

    //Output the result
    printf("The sum of elements at indices %d and %d is: %d\n", index1, index2, sum);


    //Free allocated memory
    free(array);

    return 0;
}