#include <stdio.h>
#include <stdlib.h>

int main() {
    int N; //Size N of the array
    int *array; //Pointer for dynamically allocated array
    int index1, index2; //Indices provided by the user
    int sum; //Sum of the two elements

    // Prompt the user to enter the size of the array (N must be >= 5)
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &N);
        if (N < 5) {
            printf("Error: The size of the array must be at least 5.\n");
        }
    } while (N < 5); //Repeat until a valid size is entered

    //Allocate memory for the array dynamically
    array = (int *)malloc(N * sizeof(int));
    if (array == NULL) { //Check if memory allocation was successful
        printf("Memory allocation failed.\n");
        return 1; //Exit the program if allocation fails
    }

    // Prompt the user to input elements of the array
    printf("Enter %d elements of the array:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &array[i]);
    }

    //Prompt the user to input two valid indices and validate it
    do {
        printf("Enter two indices (0 <= index1, index2 < %d): ", N);
        scanf("%d %d", &index1, &index2); //Corrected format string
        if (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N) {
            printf("Error: Indices must be in the range [0, %d).\n", N);
        }
    } while (index1 < 0 || index1 >= N || index2 < 0 || index2 >= N); //Repeat until valid indices are provided

    //Calculate the sum of the elements at the two indices using pointers
    sum = *(array + index1) + *(array + index2);

    //Print the result
    printf("Sum of elements at index %d and %d is: %d\n", index1, index2, sum);

    //Free the allocated memory to prevent memory leaks
    free(array);

    return 0;
}
