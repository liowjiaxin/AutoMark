#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    // Ask the user for array size and verify
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("The size is not valid! Please enter a value greater than or equal to 5.\n");
        }
    } while (N < 5);

    // Create a resizable array
    int* arr = (int*)malloc(N * sizeof(int));

    // checking if memory is allocated successfully
    if (arr == NULL) {
        printf("Memory allocation not successful!\n");
        return -1;
    }

    // Ask user to enter each element of the array
    printf("Enter %d elements:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", arr + i);
    }

    int index1, index2;

    // Ask the user for position of array and verify
    do {
        printf("Enter the position of the two elements (0 to %d):\n", N - 1);
        printf("Index 1: ");
        scanf("%d", &index1);
        printf("Index 2: ");
        scanf("%d", &index2);

        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Invalid index(es)! Please enter values within the range.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    // Calculate the sum using a pointer
    int sum = *(arr + index1) + *(arr + index2);

    // Print the output
    printf("Element at Index %d: %d\n", index1, *(arr + index1));
    printf("Element at Index %d: %d\n", index2, *(arr + index2));
    printf("The sum of the two elements is: %d\n", sum);

    // memory allocated during run time
    free(arr);

    return 0;
}
