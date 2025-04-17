 #include <stdio.h>
#include <stdlib.h>

int main() {
    int N, index1, index2;

    // Step 1: Prompt for size N of the array
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("The size must be at least 5.\n");
        }
    } while (N < 5);

    // Step 2: Dynamically allocate memory for the array
    int* arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Step 3: Prompt the user to enter each element of the array
    printf("Enter elements of the array:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Step 4: Prompt for two indices and validate them
    do {
        printf("Enter the indices of the two element (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Error:Indices must be within the range of the array elements. Please try again.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    // Step 5: Use pointers to access the array elements
    int* ptr1 = arr + index1;
    int* ptr2 = arr + index2;
    int sum = *ptr1 + *ptr2;

    // Step 6: Print the sum of the two elements
    printf("Sum of the values at indices %d and %d: %d\n", index1, index2, sum);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
