#include <stdio.h>
#include <stdlib.h>

int main()
{   
    // Introduce the element
    int N;
    int *array;
    int index1, index2;
    int sum;

    // Prompt user for the size of the array
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Invalid size. Please enter a value greater than or equal to 5.\n");
        }
    } while (N < 5);


    // Allocate memory for the array
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }
    
    // Prompt user to enter each element of the array
    printf("Enter %d elements of the array:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &array[i]);
    }

    // Prompt user to enter two valid indices
    do {
        printf("Enter two indices (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2);
        
        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Invalid indices. Please enter valid indices within range.\n");
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N);

    // Use pointers to find the sum of the values of the two array elements
    int *ptr1 = &array[index1];
    int *ptr2 = &array[index2];
    
    sum = *ptr1 + *ptr2;

    // Print the output for the sum
    printf("The sum of elements at indices %d and %d is: %d\n", index1, index2, sum);

    // Free allocated memory
    free(array);
    
    return 0;
}



