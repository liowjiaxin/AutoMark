//Question 1
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, index1, index2;
    int *array;

    //Prompts the user to enter the size of the array
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
    } while (N < 5);

    //Dynamically allocates memory for the array
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    //Prompts the user to input each element of the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    //Prompts the user to input the two indices
    do {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    //Computes the sum of the two target elements using pointers
    int sum = *(array + index1) + *(array + index2);

    //Prints the output for the sum
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    //Frees the allocated memory
    free(array);

    return 0;
}
