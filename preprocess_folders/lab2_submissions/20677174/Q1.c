#include <stdio.h>

int main (void) {
    int size; // Size of the array
    int index1; // First index 
    int index2; // Second index
    int sum; // Sum of elements at first index and second index

    // Prompt user input for size and validate the size 
    // Ask user to enter again if invalid
    while (1) {
        printf("Enter the size of the array (N >= 5): ");
        scanf("%d", &size);
        if (size >= 5) {
            break;
        }
        printf("Error: Size N must be >= 5");
    }

    // Declare array based on size N input by user
    int nums[size];


    // Prompt user input for N array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; ++i) {
        printf("Element %d: ", i);
        scanf("%d", nums+i);
    }

    // Prompt user input for two indices of the array elements and validate them
    // Ask user to input again if invalid
    while (1) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ", size);
        scanf("%d %d", &index1, &index2);
        // Validate by checking if both index1 and index2 are within the range (>=0 and < size)
        if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size ) {
            break;
        }
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
    }
    
    // Calculate the sum using pointer arithmetic and display the sum
    sum = *(nums + index1) + *(nums + index2);
    printf("The sum of the values at indices %d and %d is: %d", index1, index2, sum);
    
    return 0;
}