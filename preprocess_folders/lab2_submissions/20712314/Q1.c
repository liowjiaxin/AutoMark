#include <stdio.h>
#include <stdlib.h>

int main() {
    int first = 0;
    int second = 0;
    int N = 0;

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);

    // Validate if N >= 5
    while (N < 5) {
        printf("Invalid size. Please enter a size of at least 5: ");
        scanf("%d", &N);
    }

    // Dynamically allocate memory for the array using pointers
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Prompt the user to enter each element of the array
    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    // Prompt the user to enter the two indices of the array elements
    printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", N);
    scanf("%d %d", &first, &second);

    // Validate the indices
    while (first < 0 || first >= N || second < 0 || second >= N) {
        printf("Error: Indices must be within the range of the array elements. Please try again: ");
        scanf("%d %d", &first, &second);
    }

    // Calculate the sum of the two target elements using pointers
    int sum = *(array + first) + *(array + second);

    // Print the output for the sum
    printf("The sum of the values at indices %d and %d is: %d\n", first, second, sum);


    return 0;
}
