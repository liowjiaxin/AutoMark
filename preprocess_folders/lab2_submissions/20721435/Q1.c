#include <stdio.h>
#include <stdlib.h>

// prompt user to enter the size of the array where the size must be greater than or equal to 5
int main() {
    printf("Enter the size of the array (N >= 5): ");
    int N;
    int *ptr;
    scanf("%d", &N);
    while (N < 5) {
        printf("Error: Size of the array must be >= 5. Please try again: "); // Error message displayed when the size of the array is less than 5 and prompt user to enter again
        scanf("%d", &N);
    }
    int arr[N];
    // Memory allocates dynamically using malloc()
    ptr = (int *)malloc(N * sizeof(int));

    // Checking for memory allocation
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
    } else {
        // prompt user to enter the array elements where the number of elements must be equal to the size-1 of the array
        printf("Enter the array elements: \n");
        for (int i = 0; i < N; i++) {
            printf("Element %d: ", i);
            scanf("%d", &arr[i]);
        }

        // prompt user to enter the indices of two elements where the indices must be within the range of the array elements
        do {
            printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
            int index1, index2;
            scanf("%d %d", &index1, &index2);

            if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
                // calculate the sum of the values at the indices and display the sum
                int sum = *(arr + index1) + *(arr + index2);
                printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);
                break;
            } else {
                printf("Error: Indices must be within the range of the array elements. Please try again.\n"); // Error message displayed when the indices are not in range
            }
        } while (1);
    }

    free(ptr);

    return 0;
}