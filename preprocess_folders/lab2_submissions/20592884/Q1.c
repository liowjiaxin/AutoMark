#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, index1, index2;

    //Ask the user to enter the size of the array
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Invalid input. N must be greater than or equal to 5.\n");
        }
    } while (N < 5);

    //Allocate memory to the array dynamically
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    //Ask user to enter each element one by one
    printf("Enter %d elements for the array:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &array[i]);
    }

    //Ask user for the number of the indices and validate them
    while (1) {
        printf("Enter the first index (0 to %d): ", N - 1);
        scanf("%d", &index1);

        printf("Enter the second index (0 to %d): ", N - 1);
        scanf("%d", &index2);

        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            break;
        } else {
            printf("Invalid indices. Please enter indices within the range 0 to %d.\n", N - 1);
        }
    }

    //Calculate the sum using pointers
    int sum = *(array + index1) + *(array + index2);

    //Show the sum
    printf("The sum of the elements at indices %d and %d is: %d\n", index1, index2, sum);

    //Free the dynamically allocated memory
    free(array);

    return 0;
}
