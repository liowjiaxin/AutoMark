#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int* arr;
    int index1, index2;

    // Prompt user to enter the size of the array
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf_s("%d", &N);
        if (N < 5) {
            printf("Invalid input. Please enter again.\n");
        }
    } while (N < 5);

    // Memory allocates dynamically using malloc()
    arr = (int*)malloc(N * sizeof(int));

    // checking for memory allocation
    if (arr == NULL) {
        printf("Memory not allocated.\n");
    }
    else {
        // Prompt the user to enter array elements
        printf("Enter %d elements for the array:\n", N);
        for (int i = 0; i < N; i++) {
            printf("Element %d: ", i);
            scanf_s("%d", &arr[i]);
        }

        // Prompt the user to enter two indices
        do {
            printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
            scanf_s("%d %d", &index1, &index2);
            if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) { // check if it is a valid indices
                printf("Error: Indices must be in the range of the array elements. Please try again.\n");
            }
        } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

        // Calculate the sum
        int sum = *(arr + index1) + *(arr + index2);

        // Print the sum
        printf("The sum of the elements at indices %d and %d is: %d\n", index1, index2, sum);
    }

    free(arr);

    return 0;
}
