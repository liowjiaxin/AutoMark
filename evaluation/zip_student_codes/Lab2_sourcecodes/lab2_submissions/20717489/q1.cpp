#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
    int* arr;  // Pointer to dynamically allocate array
    int N, index1, index2;
    int sum;

    //Prompt user to enter the size N of the array, validate if N ¡Ý 5
    do {
        printf("Enter the size of the array (N ¡Ý 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Error: Array size must be at least 5.\n");
        }
    } while (N < 5);

    //Dynamically allocate memory for the array
    arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Exit the program if memory allocation fails
    }

    //Prompt user to enter each element of the array
    printf("Enter %d elements of the array:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    //Prompt the user to enter the two indices, validate the indices
    do {
        printf("Enter the first index (0 ¡Ü index1 < %d): ", N);
        scanf("%d", &index1);
        printf("Enter the second index (0 ¡Ü index2 < %d): ", N);
        scanf("%d", &index2);

        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Error: Indices must be within the range 0 to %d.\n", N - 1);
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    //Use pointer-based approach to compute the sum of the values at the two indices
    int* ptr1 = arr + index1;  // Pointer to the first element
    int* ptr2 = arr + index2;  // Pointer to the second element
    sum = *ptr1 + *ptr2;  // Dereference pointers to get the values and compute the sum

    //Print the sum of the two target elements
    printf("The sum of elements at indices %d and %d is: %d\n", index1, index2, sum);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}