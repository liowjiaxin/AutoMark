#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arrayPtr = NULL; // initialize pointer for dynamic memory allocation as NULL
    int index1, index2, size = 0, sum = 0; //declare the variables

    // prompt user to enter size of the array (N >= 5) at least once
    do {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &size);
        if (size < 5) {
            printf("Invalid size. Size must be >= 5. Try again.\n"); 
        }
    } while (size < 5); //if input is invalid, loop back

    // allocate memory for the array
    arrayPtr = (int *)malloc(size * sizeof(int));

    //check whether memory allocation is success
    if (arrayPtr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1; // exit if memory allocation fails
    }

    // prompt user to enter array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arrayPtr[i]);
    }

    // prompt user to enter two indices 
    do {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", size);
        scanf("%d %d", &index1, &index2);

        //check whether the indices are valid and print error message
        if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        }
    } while (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size);

    // calculate sum using pointer-based approach
    sum = *(arrayPtr + index1) + *(arrayPtr + index2);

    // display the result
    printf("The sum of the values at indices %d and %d is: %d\n", index1, index2, sum);

    // free dynamically allocated memory
    free(arrayPtr);

    return 0;
}
