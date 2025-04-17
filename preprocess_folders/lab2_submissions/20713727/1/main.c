#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int *arr;
    int index1;
    int index2;
    int sum;

    // Prompt the user for the size of the array and validate
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);
    while (N < 5) {
        printf("Size must be at least 5. Please re-enter: ");
        scanf("%d", &N);
    }

    // Dynamically allocate memory for the array
    arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; 
    }

    // Prompt the user to enter each element of the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", arr + i); // Use pointer notation
    }

    // Prompt the user to enter two valid indices
    while (1) {
        printf("Enter the first index (0 to %d): ", N - 1);
        scanf("%d", &index1);
        printf("Enter the second index (0 to %d): ", N - 1);
        scanf("%d", &index2);

        if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
            break; // Indices are valid
        } else {
            printf("error: Indices must be within the range of the array elements. Please try again.\n");
        }
    }

    sum = *(arr + index1) + *(arr + index2);
    printf("The sum of elements at index %d and %d is: %d\n", index1, index2, sum);
    
    return 0;
}
