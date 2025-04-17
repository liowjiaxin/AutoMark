#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, *array, index1, index2;

    //Prompt the user for the size of the array (N) and validate
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Error: Size of the array must be at least 5.\n");
        }
    } while (N < 5);

    //Dynamically allocate memory for the array
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    //Prompt the user to enter array elements
    printf("Enter the array elements:\n");

    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    //Prompt the user for indices and validate
    do {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);

        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    //Calculate the sum using pointers
    int sum = *(array + index1) + *(array + index2);

    //Print the result
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    //Free allocated memory
    free(array);

    return 0;
}